#pragma once
#include <QVariantList>
#include "dbtypes.h"
#include "Executor.h"

namespace db
{
class Selector
{
public:
    DBTypes::DBResult selectAll(const std::string& tableName,
                                std::vector<QVariantList>& returnData);

private:
    Executor m_executor;
    std::string generateQuery(const std::string& tableName) const;
};
}
