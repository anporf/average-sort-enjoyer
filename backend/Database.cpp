#include "Database.h"

Database::Database(const std::string& connection_info) : conn_(connection_info) {}

pqxx::result Database::query(const std::string& sql) {
    pqxx::work w(conn_);
    auto result = w.exec(sql);
    w.commit();
    return result;
}

void Database::execute(const std::string& sql) {
    pqxx::work w(conn_);
    w.exec(sql);
    w.commit();
}
