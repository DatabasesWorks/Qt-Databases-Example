#ifndef DBPROCESSING_H
#define DBPROCESSING_H
#include <vector>
#include <QVariantList>
#include "dbtypes.h"

class DBProcessing
{
public:
    DBProcessing();
#ifdef INSERT_TEST_DATA
    void insertTestData();
#endif

    std::pair<DBTypes::DBResult, std::vector<DBTypes::DBEntry>> requestTableData(DBTypes::DBTables table);
};

#endif // DBPROCESSING_H
