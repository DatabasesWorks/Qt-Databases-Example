#include "dbprocessing.h"

#include "dbselector.h"
#include "dbmanipulator.h"

static DBSelector selector;

DBProcessing::DBProcessing()
{
#ifdef INSERT_TEST_DATA
#endif
}

static const std::map<DBTypes::DBTables, std::string> tableMapper {
    {DBTypes::DBTables::Contacts, "Contacts"}
};

#ifdef INSERT_TEST_DATA
void DBProcessing::insertTestData()
{
    DBManipulator dbManipulator;
    dbManipulator.insertRow("Contacts", {{"Wylie", "Johns", "380618395414"}});
    dbManipulator.insertRow("Contacts", {{"Asher", "Blankenship", "380158932138"}});
    dbManipulator.insertRow("Contacts", {{"Eric", "French", "380277473644"}});
    dbManipulator.insertRow("Contacts", {{"Michael", "Cooper", "380999986699"}});
    dbManipulator.insertRow("Contacts", {{"Ulric", "Shepherd", "380626465726"}});
    dbManipulator.insertRow("Contacts", {{"Lionel", "Holt", "380454835415"}});
    dbManipulator.insertRow("Contacts", {{"Aquila", "Tanner", "380813526568"}});
    dbManipulator.insertRow("Contacts", {{"Lee", "Booth", "380423227258"}});
    dbManipulator.insertRow("Contacts", {{"Drew", "Branch", "380955112745"}});
    dbManipulator.insertRow("Contacts", {{"Francis", "Buckley", "380658457417"}});
    dbManipulator.insertRow("Contacts", {{"Stuart", "Wright", "380813526568"}});
    dbManipulator.insertRow("Contacts", {{"Leonard", "Tanner", "380813526568"}});
    dbManipulator.insertRow("Contacts", {{"Christopher", "Dillon", "380565828659"}});
    dbManipulator.insertRow("Contacts", {{"", "Ivanov", "380501728834"}});
}
#endif

std::pair<DBTypes::DBResult, std::vector<DBTypes::DBEntry>> DBProcessing::requestTableData(DBTypes::DBTables table)
{
}
