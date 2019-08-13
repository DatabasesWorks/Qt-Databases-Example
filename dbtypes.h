#ifndef DBTYPES_H
#define DBTYPES_H

namespace DBTypes
{
enum class DBResult {
    OK,
    FAIL
};

enum class DBTables {
    Goods = 1,
    Categories = 2,
    Providers = 3
};

enum class DBState {
    OK,
    ERROR_NO_DRIVER,
    ERROR_WORKSPACE,
    ERROR_TABLES,
    ERROR_OPENING
};
}
#endif // DBTYPES_H
