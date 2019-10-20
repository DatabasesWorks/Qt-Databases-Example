#pragma once
#include <QMap>
#include <QDebug>
#include <QSqlQuery>
#include "ConnectionManager.h"

namespace db
{
class Executor
{
public:
    Executor();
    Q_DISABLE_COPY(Executor)

    std::pair<DBTypes::DBResult, QSqlQuery> execute(const std::string& queryText, const QVariantList& args = {});

private:
    ConnectionManager& m_connectionManager;
};
}
