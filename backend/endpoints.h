#ifndef ENDPOINTS_H
#define ENDPOINTS_H

#include "Database.h"
#include <crow.h>

void setupEndpoints(Database& db, crow::SimpleApp& app);

#endif // ENDPOINTS_H
