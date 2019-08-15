#ifndef DBINSERTER_H
#define DBINSERTER_H
#include "dbmanager.h"
#include "dbtypes.h"

class DBManipulator
{
public:
    DBManipulator();

    std::pair<DBTypes::DBResult, int> insertRow(const std::string& tableName, const QVariantList& rowData);

private:
    DBManager& m_dbManager;
    std::string generateBindString(size_t paramCount) const;
    std::string generateInsertQuery(const std::string& tableName, size_t paramCount) const;
    std::string generateSetString(const QVector<QString>& columns, const QVariantList& values) const;
};

#endif // DBINSERTER_H
