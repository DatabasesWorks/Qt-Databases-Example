#ifndef DBPROCESSING_H
#define DBPROCESSING_H
#include <vector>
#include <QVariantList>
#include "dbtypes.h"
#include "dbselector.h"
#include "dbmanipulator.h"

class DBProcessing
{
public:
    DBProcessing();
#ifdef INSERT_TEST_DATA
    void insertTestData();
#endif

    std::pair<DBTypes::DBResult,
              std::vector<QVariantList>> requestTableData(DBTypes::DBTables table);
private:
    DBSelector m_selector;
};

#endif // DBPROCESSING_H
