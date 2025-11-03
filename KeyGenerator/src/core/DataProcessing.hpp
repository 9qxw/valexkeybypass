#pragma once
#include "../../include/CommonHeaders.hpp"

namespace DataProc {
    class ResponseParser {
    public:
        static std::string ExtractKeyFromJson(const std::string& jsonResponse) {
            try {
                auto jsonData = json::parse(jsonResponse);
                if (jsonData.contains("success") && jsonData["success"] == true && jsonData.contains("key")) {
                    return jsonData["key"].get<std::string>();
                }
            } catch (const std::exception& e) {
                std::cerr << "JSON parsing error: " << e.what() << std::endl;
            }
            return "Error: Could not generate key";
        }
    };
}