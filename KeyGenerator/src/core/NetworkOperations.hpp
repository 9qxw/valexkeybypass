#pragma once
#include "../../include/CommonHeaders.hpp"

namespace NetworkOps {
    struct HttpConfig {
        std::string userAgent;
        std::vector<std::string> headers;
        std::string cookieData;
    };
    
    class ConnectionManager {
    private:
        static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
            size_t totalSize = size * nmemb;
            output->append((char*)contents, totalSize);
            return totalSize;
        }
        
    public:
        static std::string PerformPostRequest(const std::string& url, const std::string& postData, const HttpConfig& config) {
            CURL* curl = curl_easy_init();
            std::string responseBuffer;
            
            if (curl) {
                struct curl_slist* headerList = nullptr;
                for (const auto& header : config.headers) {
                    headerList = curl_slist_append(headerList, header.c_str());
                }
                
                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);
                curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerList);
                curl_easy_setopt(curl, CURLOPT_USERAGENT, config.userAgent.c_str());
                curl_easy_setopt(curl, CURLOPT_COOKIE, config.cookieData.c_str());
                
                curl_easy_perform(curl);
                curl_slist_free_all(headerList);
                curl_easy_cleanup(curl);
            }
            
            return responseBuffer;
        }
    };
}