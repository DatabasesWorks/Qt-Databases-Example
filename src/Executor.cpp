#include "Executor.h"
#include <QSqlError>
#include <QDebug>

using namespace DBTypes;

namespace db
{
Executor::Executor()
    : m_connectionManager {ConnectionManager::instance()}
{

}

std::pair<DBResult, QSqlQuery> Executor::execute(const std::string& queryText, const QVariantList& args)
{
    QSqlQuery query {QString::fromStdString(queryText)};

    for(int i = 0; i < args.size(); ++i)
    {
        query.bindValue(i, args[i]);
    }

    DBResult result {DBResult::OK};

    if(!query.exec() && query.lastError().isValid())
    {
        qCritical() << query.lastError().text()<< query.lastQuery();
        result = DBResult::FAIL;
    }

    return std::make_pair(result, query);
}
}
