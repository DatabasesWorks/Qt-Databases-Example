#include "Processor.h"
#include "Manipulator.h"
#include "Selector.h"
#include "dbmapper.h"
#include <mutex>

namespace db
{
struct Processor::ProcessorPrivate
{
    Manipulator manipulator;
    Selector selector;
#ifdef INSERT_TEST_DATA
    void insertMockData();
    std::once_flag initialized;
#endif
};

#ifdef INSERT_TEST_DATA
void Processor::ProcessorPrivate::insertMockData()
{
    manipulator.insertRow("Contacts", {{"Wylie", "Johns", "380618395414"}});
    manipulator.insertRow("Contacts", {{"Asher", "Blankenship", "380158932138"}});
    manipulator.insertRow("Contacts", {{"Eric", "French", "380277473644"}});
    manipulator.insertRow("Contacts", {{"Michael", "Cooper", "380999986699"}});
    manipulator.insertRow("Contacts", {{"Ulric", "Shepherd", "380626465726"}});
    manipulator.insertRow("Contacts", {{"Lionel", "Holt", "380454835415"}});
    manipulator.insertRow("Contacts", {{"Aquila", "Tanner", "380813526568"}});
    manipulator.insertRow("Contacts", {{"Lee", "Booth", "380423227258"}});
    manipulator.insertRow("Contacts", {{"Drew", "Branch", "380955112745"}});
    manipulator.insertRow("Contacts", {{"Francis", "Buckley", "380658457417"}});
    manipulator.insertRow("Contacts", {{"Stuart", "Wright", "380813526568"}});
    manipulator.insertRow("Contacts", {{"Leonard", "Tanner", "380813526568"}});
    manipulator.insertRow("Contacts", {{"Christopher", "Dillon", "380565828659"}});
    manipulator.insertRow("Contacts", {{"", "Ivanov", "380501728834"}});
}
#endif

db::Processor::Processor()
    : m_d {new ProcessorPrivate {}}
{
#ifdef INSERT_TEST_DATA
    auto inserter = [this] {
        m_d->insertMockData();
    };
    std::call_once(m_d->initialized, inserter);
#endif
}

Processor::~Processor()
{
}

std::pair<DBTypes::DBResult, std::vector<DBTypes::DBEntry>> Processor::requestTableData(DBTypes::DBTables table)
{
    std::vector<QVariantList> result;
    const DBTypes::DBResult resultState {m_d->selector.selectAll(tableMapper.at(table), result)};
    return std::make_pair(resultState, std::move(result));
}
}
