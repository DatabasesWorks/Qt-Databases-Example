#include "dbmanager.h"
#include <QSqlError>
#include <QDebug>

using namespace DBTypes;

DBManager& DBManager::instance()
{
}

std::pair<DBResult, QSqlQuery> DBManager::execute(const std::string& queryText, const QVariantList& args)
{
}
