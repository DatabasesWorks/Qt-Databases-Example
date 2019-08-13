#include "dbconnectionmanager.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QDir>

using namespace DBTypes;

namespace
{
    class DBCloser {
    public:
        void operator() (QSqlDatabase* db) {
            db->close();
        }
    };
}

class DBConnectionManager::DBManagerPrivate {
public:
    mutable bool m_isValid {true};
    std::unique_ptr<QSqlDatabase, DBCloser> m_database;
    std::string m_dbPath;
    DBState m_state {DBState::OK};
};

std::string DBConnectionManager::databasePath() const
{
    return m_d->m_dbPath;
}

DBState DBConnectionManager::state() const
{
    return m_d->m_state;
}

bool DBConnectionManager::setUp()
{
    const QString driver {"QSQLITE"};

    if (!QSqlDatabase::isDriverAvailable(driver)) {
        m_d->m_state = DBState::ERROR_NO_DRIVER;
        qWarning() << "Driver " << driver << " is not available.";
        return false;
    }

    if (!setUpWorkspace()) {
        m_d->m_state = DBState::ERROR_WORKSPACE;
        qWarning() << "Workspace setup failed!";
        return false;
    }

    auto* db = new QSqlDatabase {QSqlDatabase::addDatabase(driver)};
    m_d->m_database.reset(db);
    m_d->m_database->setDatabaseName(QString::fromStdString(m_d->m_dbPath));

    qDebug() << "Database name: " << m_d->m_database->databaseName();

    if (!m_d->m_database->open()) {
        m_d->m_state = DBState::ERROR_OPENING;
        qWarning() << "Error in opening DB " << m_d->m_database->databaseName()
                   << " reason: " <<  m_d->m_database->lastError().text();
        return false;
    }

    return setUpTables();
}

bool DBConnectionManager::setUpWorkspace()
{
#ifdef BUILD_TESTS
    const QString databaseName {"TestDB"};
#else
    const QString databaseName {"GoodsDB"};
#endif
    const QString location {QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)};
    const QString fullPath {location + "/" + databaseName};

    m_d->m_dbPath = fullPath.toStdString();

    QDir dbDirectory {location};
    if (!dbDirectory.exists()) {
        qWarning() << "DB directory not exist, creating result: "
                   << dbDirectory.mkpath(location);
    }

    qDebug() << "Data path: " << fullPath;

    return dbDirectory.exists();
}

bool DBConnectionManager::setUpTables()
{
    bool result {true};

    std::vector<QSqlQuery> creationQueries = {
        QSqlQuery {
            "CREATE TABLE IF NOT EXISTS Products"
            "("
            "Name TEXT UNIQUE NOT NULL,"
            "CategoryId INTEGER NOT NULL,"
            "Brand TEXT,"
            "Amount INTEGER DEFAULT 0,"
            "Price INTEGER DEFAULT 1,"
            "BarCode INTEGER);"
        },
        QSqlQuery {
            "CREATE TABLE IF NOT EXISTS Categories"
            "("
            "Name TEXT UNIQUE NOT NULL,"
            "ProviderId INTEGER NOT NULL);"
        },
        QSqlQuery {
            "CREATE TABLE IF NOT EXISTS Providers"
            "("
            "Name TEXT NOT NULL,"
            "Surname TEXT NOT NULL,"
            "Identity INTEGER NOT NULL,"
            "PhoneNumber TEXT,"
            "UNIQUE (Name, Surname));"
        },
        QSqlQuery {
            "CREATE VIEW IF NOT EXISTS CategoryView AS "
            "SELECT Categories.rowid, Categories.Name, Providers.Name as ProviderName, Providers.Surname as ProviderSurname, Providers.rowid as ProviderId "
            "FROM Categories, Providers "
            "WHERE Categories.ProviderId = Providers.rowid; "
        },
        QSqlQuery {
            "CREATE VIEW IF NOT EXISTS GoodsView AS "
            "SELECT Products.rowid, Products.Name, Products.CategoryId, Categories.Name as CategoryName, Products.Brand, "
            "Products.Amount, Products.Price, Products.BarCode "
            "FROM Products, Categories "
            "WHERE Products.CategoryId = Categories.rowid "
        }
    };

    for (auto& query : creationQueries) {
        if (!query.exec()) {
            result = false;
            m_d->m_state = DBState::ERROR_TABLES;
            qWarning() << "Table creation failed. Reason: "
                       << query.lastError();
        } else {
            qWarning() << "Table successfully created! Query: \n" << query.lastQuery();
        }
    }

    return result;
}

void DBConnectionManager::setIsValid(bool isValid)
{
    m_d->m_isValid = isValid;
}

bool DBConnectionManager::isValid() const
{
    return m_d->m_isValid && m_d->m_database->isValid();
}

DBConnectionManager::DBConnectionManager()
    : m_d {new DBManagerPrivate {}}
{
    setIsValid(setUp());
}

DBConnectionManager::~DBConnectionManager()
{
}
