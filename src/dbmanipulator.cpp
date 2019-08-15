#include "dbmanipulator.h"
#include <sstream>

using namespace DBTypes;

namespace {
static const std::map<std::string, std::string> tablesMapping = {
    {"Contacts", "Name, Surname, PhoneNumber"},
};
}

DBManipulator::DBManipulator()
{
}

std::pair<DBResult, int> DBManipulator::insertRow(const std::string& tableName, const QVariantList& rowData)
{
}

std::string DBManipulator::generateBindString(size_t paramCount) const
{
}

std::string DBManipulator::generateInsertQuery(const std::string& tableName, size_t paramCount) const
{
}