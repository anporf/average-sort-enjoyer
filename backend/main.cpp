// backend/main.cpp
#include "Database.h"
#include "endpoints.h"
#include <crow.h>
#include <string>

int main() {
    crow::SimpleApp app;
    std::string conn_info = "postgresql://anporf:anporf@db/data";
    Database db(conn_info);

    setupEndpoints(db, app);
    app.port(8080).multithreaded().run();

    return 0;
}
