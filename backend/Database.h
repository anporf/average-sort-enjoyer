// backend/Database.h
#ifndef DATABASE_H
#define DATABASE_H

#include <pqxx/pqxx>
#include <string>

class Database {
public:
    Database(const std::string& connection_info);
    pqxx::result query(const std::string& sql);
    void execute(const std::string& sql);

private:
    pqxx::connection conn_;
};

#endif // DATABASE_H
