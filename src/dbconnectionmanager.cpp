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
}

DBState DBConnectionManager::state() const
{
}

bool DBConnectionManager::setUp()
{
}

bool DBConnectionManager::setUpWorkspace()
{
#ifdef BUILD_TESTS
    const QString databaseName {"TestDB"};
#else
    const QString databaseName {"ContactsDB"};
#endif
}

bool DBConnectionManager::setUpTables()
{
}

void DBConnectionManager::setIsValid(bool isValid)
{
}

bool DBConnectionManager::isValid() const
{
}

DBConnectionManager::DBConnectionManager()
{
}

DBConnectionManager::~DBConnectionManager()
{
}
