#include "dbselector.h"
#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlRecord>

using namespace DBTypes;

DBSelector::DBSelector()
    : m_dbManager {DBManager::instance()}
{
}

DBResult DBSelector::selectAll(const std::string& tableName, std::vector<QVariantList>& returnData)
{
}

std::string DBSelector::generateQuery(const std::string& tableName) const
{
}
