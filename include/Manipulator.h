#pragma once
#include "Executor.h"
#include "dbtypes.h"

namespace db
{
class Manipulator
{
public:
    std::pair<DBTypes::DBResult, int> insertRow(const std::string& tableName, const QVariantList& rowData);

private:
    Executor m_executor;
    std::string generateBindString(size_t paramCount) const;
    std::string generateInsertQuery(const std::string& tableName, size_t paramCount) const;
    std::string generateSetString(const QVector<QString>& columns, const QVariantList& values) const;
};
}

