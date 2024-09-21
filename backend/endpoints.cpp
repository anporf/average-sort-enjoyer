#include "endpoints.h"

void setupEndpoints(Database& db, crow::SimpleApp& app) {
    CROW_ROUTE(app, "/getList/<int>")
    ([&db](int list_id) {
        auto result = db.query("SELECT * FROM Lists WHERE ID = " + std::to_string(list_id));
        if (result.empty()) return crow::response(404, "List not found");
        crow::json::wvalue json;
        json["ID"] = result[0]["ID"].as<int>();
        json["Items"] = result[0]["Items"].as<std::string>(); // need to parse ARRAY manually
        json["Name"] = result[0]["Name"].as<std::string>();
        json["Image_Url"] = result[0]["Image_Url"].as<std::string>();
        json["Description"] = result[0]["Description"].as<std::string>();
        return crow::response(json);
    });

    CROW_ROUTE(app, "/getItem/<int>")
    ([&db](int item_id) {
        auto result = db.query("SELECT * FROM Items WHERE ID = " + std::to_string(item_id));
        if (result.empty()) return crow::response(404, "Item not found");
        crow::json::wvalue json;
        json["ID"] = result[0]["ID"].as<int>();
        json["Name"] = result[0]["Name"].as<std::string>();
        json["Image_Url"] = result[0]["Image_Url"].as<std::string>();
        json["Description"] = result[0]["Description"].as<std::string>();
        return crow::response(json);
    });

    CROW_ROUTE(app, "/addItem").methods("POST"_method)
    ([&db](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body) return crow::response(400, "Invalid JSON");
        std::string name = body["Name"].s();
        std::string image_url = body["Image_Url"].s();
        std::string description = body["Description"].s();
        db.execute("INSERT INTO Items (Name, Image_Url, Description) VALUES ('" +
                   name + "', '" + image_url + "', '" + description + "')");
        return crow::response(201, "Item added");
    });

    CROW_ROUTE(app, "/addList").methods("POST"_method)
    ([&db](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body) return crow::response(400, "Invalid JSON");
        std::string name = body["Name"].s();
        std::string image_url = body["Image_Url"].s();
        std::string description = body["Description"].s();
        std::string items = body["Items"].dump();
        db.execute("INSERT INTO Lists (Name, Image_Url, Description, Items) VALUES ('" +
                   name + "', '" + image_url + "', '" + description + "', '" + items + "')");
        return crow::response(201, "List added");
    });
}