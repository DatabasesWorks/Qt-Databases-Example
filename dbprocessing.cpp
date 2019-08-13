#include "dbprocessing.h"
#include "dbmanipulator.h"

DBProcessing::DBProcessing()
{
#ifdef INSERT_TEST_DATA
    insertTestData();
#endif
}

static const std::map<DBTypes::DBTables, std::string> tableMapper {
    {DBTypes::DBTables::Providers, "Providers"},
    {DBTypes::DBTables::Categories, "Categories"},
    {DBTypes::DBTables::Goods, "Products"}
};

static const std::map<DBTypes::DBTables, std::string> selectionMapper {
    {DBTypes::DBTables::Providers, "Providers"},
    {DBTypes::DBTables::Categories, "CategoryView"},
    {DBTypes::DBTables::Goods, "GoodsView"}
};

#ifdef INSERT_TEST_DATA
void DBProcessing::insertTestData()
{
    DBManipulator dbManager;
    dbManager.insertRow("Providers", {{"Dmytro"}, {"Afanasiev"}, {10000}, {"+38050180126"}});
    dbManager.insertRow("Providers", {{"Johnny"}, {"Bold"}, {20000}, {"+3803480125"}});
    dbManager.insertRow("Providers", {{"Ivan"}, {"Race"}, {14550}, {"+38050180126"}});
    dbManager.insertRow("Providers", {{"Ludmila"}, {"Vasilyeva"}, {25500}, {"+3804450125"}});
    dbManager.insertRow("Providers", {{"Alexandr"}, {"Kukulkan"}, {13400}, {"+38044180126"}});
    dbManager.insertRow("Providers", {{"Marina"}, {"Sofieva"}, {25566}, {"+38034823125"}});
    dbManager.insertRow("Providers", {{"Sofiia"}, {"Kusok"}, {98776}, {"+380501802436"}});
    dbManager.insertRow("Providers", {{"Danky"}, {"Memes"}, {876611}, {"+38034802355"}});

    dbManager.insertRow("Categories", {{"Displays"}, {1}});
    dbManager.insertRow("Categories", {{"Computers"}, {1}});
    dbManager.insertRow("Categories", {{"Powerblock"}, {2}});
    dbManager.insertRow("Categories", {{"HDD Disks"}, {3}});
    dbManager.insertRow("Categories", {{"SSD disks"}, {4}});
    dbManager.insertRow("Categories", {{"Motherboards"}, {5}});
    dbManager.insertRow("Categories", {{"Processors"}, {6}});
    dbManager.insertRow("Categories", {{"Cables"}, {7}});

    dbManager.insertRow("Products", {{"27'' Samsung Curved C27F396F"}, {1}, {"Samsung"}, {230}, {10000}, {91919234}});
    dbManager.insertRow("Products", {{"Western Digital Blue 1TB 7200rpm 64MB WD10EZEX"}, {4}, {"Western Digital Blue "}, {19}, {2300}, {91919554}});
    dbManager.insertRow("Products", {{"Everest Home&Office 1006"}, {2}, {"Everest"}, {65}, {4000}, {91449234}});
    dbManager.insertRow("Products", {{"Aerocool VX-700 700W"}, {3}, {"Aerocool"}, {5}, {2300}, {92249234}});
    dbManager.insertRow("Products", {{"Kingston SSDNow A400 120GB 2.5'' SATAIII TLC"}, {5}, {"Kingston"}, {25}, {800}, {91445234}});
    dbManager.insertRow("Products", {{"MSI B450 Tomahawk"}, {6}, {"MSI"}, {109}, {4500}, {91467234}});
    dbManager.insertRow("Products", {{"Intel Core i3-8100 3.6GHz/8GT/s/6MB"}, {7}, {"Intel"}, {33}, {4550}, {91423234}});
    dbManager.insertRow("Products", {{"STLab HDMI - VGA"}, {8}, {"STLAB"}, {400}, {40}, {92245234}});
}
#endif

std::pair<DBTypes::DBResult, std::vector<QVariantList>> DBProcessing::requestTableData(DBTypes::DBTables table)
{
    std::vector<QVariantList> result;
    DBTypes::DBResult resultState = m_selector.selectAll(selectionMapper.at(table), result);
    return std::make_pair(resultState, std::move(result));
}

std::pair<DBTypes::DBResult, int> DBProcessing::requestAddRow(DBTypes::DBTables table, const QVariantList& data)
{
    return m_manipulator.insertRow(tableMapper.at(table), data);
}

DBTypes::DBResult DBProcessing::requestUpdate(DBTypes::DBTables table, const QVector<QString>& headers, const QVariantList& data)
{
    return m_manipulator.updateValue(tableMapper.at(table), headers, data);
}

DBTypes::DBResult DBProcessing::requestDelete(DBTypes::DBTables table, int identity)
{
    return m_manipulator.deleteIdentity(tableMapper.at(table), identity);
}
