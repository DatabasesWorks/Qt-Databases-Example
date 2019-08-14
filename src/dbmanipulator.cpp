#include "dbmanipulator.h"
#include <sstream>

using namespace DBTypes;

namespace {
static const std::map<std::string, std::string> tablesMapping = {
    {"Contacts", "Name, Surname, PhoneNumber"},
};
}

DBManipulator::DBManipulator()
    : m_dbManager {DBManager::instance()}
{
}

std::pair<DBResult, int> DBManipulator::insertRow(const std::string& tableName, const QVariantList& rowData)
{
    const std::string& query {generateInsertQuery(tableName, rowData.size())};
    const std::pair<DBResult, QSqlQuery>& result {m_dbManager.execute(query, rowData)};
    return std::make_pair(result.first,
                          result.second.lastInsertId().toInt());
}

std::string DBManipulator::generateBindString(size_t paramCount) const
{
    std::ostringstream bindings;
    std::fill_n(std::ostream_iterator<std::string>(bindings),
                paramCount,
                "?,");

    std::string bindString = bindings.str();
    bindString.pop_back(); // the last ","

    return bindString;
}

std::string DBManipulator::generateInsertQuery(const std::string& tableName, size_t paramCount) const
{
    std::string query = "INSERT INTO " + tableName +  " (" + tablesMapping.at(tableName) + ")"
                        " VALUES (";

    query += generateBindString(paramCount);
    query += ")";

    return query;
}