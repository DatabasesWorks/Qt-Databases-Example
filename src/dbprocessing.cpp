#include "dbprocessing.h"

#include "dbselector.h"
#include "dbmanipulator.h"

static DBSelector selector;

DBProcessing::DBProcessing()
{
#ifdef INSERT_TEST_DATA
    insertTestData();
#endif
}

static const std::map<DBTypes::DBTables, std::string> tableMapper {
    {DBTypes::DBTables::Contacts, "Contacts"}
};

#ifdef INSERT_TEST_DATA
void DBProcessing::insertTestData()
{
    DBManipulator dbManipulator;
    dbManipulator.insertRow("Providers", {{"Dmytro"}, {"Afanasiev"}, {10000}, {"+38050180126"}});
    dbManipulator.insertRow("Providers", {{"Johnny"}, {"Bold"}, {20000}, {"+3803480125"}});
    dbManipulator.insertRow("Providers", {{"Ivan"}, {"Race"}, {14550}, {"+38050180126"}});
    dbManipulator.insertRow("Providers", {{"Ludmila"}, {"Vasilyeva"}, {25500}, {"+3804450125"}});
    dbManipulator.insertRow("Providers", {{"Alexandr"}, {"Kukulkan"}, {13400}, {"+38044180126"}});
    dbManipulator.insertRow("Providers", {{"Marina"}, {"Sofieva"}, {25566}, {"+38034823125"}});
    dbManipulator.insertRow("Providers", {{"Sofiia"}, {"Kusok"}, {98776}, {"+380501802436"}});
    dbManipulator.insertRow("Providers", {{"Danky"}, {"Memes"}, {876611}, {"+38034802355"}});

    dbManipulator.insertRow("Categories", {{"Displays"}, {1}});
    dbManipulator.insertRow("Categories", {{"Computers"}, {1}});
    dbManipulator.insertRow("Categories", {{"Powerblock"}, {2}});
    dbManipulator.insertRow("Categories", {{"HDD Disks"}, {3}});
    dbManipulator.insertRow("Categories", {{"SSD disks"}, {4}});
    dbManipulator.insertRow("Categories", {{"Motherboards"}, {5}});
    dbManipulator.insertRow("Categories", {{"Processors"}, {6}});
    dbManipulator.insertRow("Categories", {{"Cables"}, {7}});

    dbManipulator.insertRow("Products", {{"27'' Samsung Curved C27F396F"}, {1}, {"Samsung"}, {230}, {10000}, {91919234}});
    dbManipulator.insertRow("Products", {{"Western Digital Blue 1TB 7200rpm 64MB WD10EZEX"}, {4}, {"Western Digital Blue "}, {19}, {2300}, {91919554}});
    dbManipulator.insertRow("Products", {{"Everest Home&Office 1006"}, {2}, {"Everest"}, {65}, {4000}, {91449234}});
    dbManipulator.insertRow("Products", {{"Aerocool VX-700 700W"}, {3}, {"Aerocool"}, {5}, {2300}, {92249234}});
    dbManipulator.insertRow("Products", {{"Kingston SSDNow A400 120GB 2.5'' SATAIII TLC"}, {5}, {"Kingston"}, {25}, {800}, {91445234}});
    dbManipulator.insertRow("Products", {{"MSI B450 Tomahawk"}, {6}, {"MSI"}, {109}, {4500}, {91467234}});
    dbManipulator.insertRow("Products", {{"Intel Core i3-8100 3.6GHz/8GT/s/6MB"}, {7}, {"Intel"}, {33}, {4550}, {91423234}});
    dbManipulator.insertRow("Products", {{"STLab HDMI - VGA"}, {8}, {"STLAB"}, {400}, {40}, {92245234}});
}
#endif

std::pair<DBTypes::DBResult, std::vector<QVariantList>> DBProcessing::requestTableData(DBTypes::DBTables table)
{
    std::vector<QVariantList> result;
    const DBTypes::DBResult resultState {selector.selectAll(tableMapper.at(table), result)};
    return std::make_pair(resultState, std::move(result));
}
