#pragma once
#include "../core/NetworkOperations.hpp"
#include "../core/DataProcessing.hpp"

class ExecutorKeyGenerator {
private:
    NetworkOps::HttpConfig CreateConfig() {
        NetworkOps::HttpConfig cfg;
        cfg.userAgent = "Mozilla/5.0 (X11; Linux x86_64; rv:144.0) Gecko/20100101 Firefox/144.0";
        cfg.headers = {
            "Accept: application/json",
            "Accept-Language: en-US,en;q=0.5",
            "Accept-Encoding: gzip, deflate, br, zstd",
            "Referer: https://key.valex.io/",
            "Content-Type: application/json",
            "Origin: https://key.valex.io",
            "Sec-GPC: 1",
            "Connection: keep-alive",
            "Sec-Fetch-Dest: empty",
            "Sec-Fetch-Mode: cors",
            "Sec-Fetch-Site: same-origin",
            "Priority: u=4",
            "Pragma: no-cache",
            "Cache-Control: no-cache",
            "TE: trailers"
        };
        cfg.cookieData = "vkst=key.c673eA1e-87a4-4740-8803-225d523cc002.1760903053898.eaf85fa28s2db0f1a65602c03adca340767419edd0be21f19ab39674175d07a0; cf_clearance=3D1c77UMmPN1HAmUEUmikggGmGvqSZkidjLv4iLXhSQc-1761651263-1.2.1.1-d84A6Fx8nUisKMgreI9TInmD6iVM32Ktq9AluA4BwCg7aPYIqP_2zEBskSybeH.uW_g0Yl.A0jMX6H5A5oywBMawFd_z74CcrecOdkOciUUoPFpkoDtM8ZHpTpz5sQPmItFwkiqtovu8EsEbr8bgC7pEbdcXPvyMmXt4HeOzupVB.vD4RoWRnbhyyun3.ePINlCf8tnMh3Y52RkglZRFGQWysvEzhZtHwhCDDKeRVCw; cf_clearance=WrpL4IoJ_ArIFp62kF8rnd65jyW34c7DJJkQnZa.BdU-1762203780-1.2.1.1-XfBpwrWFClA1awLeU3rOR5bnW5r3k0Q3ubKw1pGHdnfURwpQeyPypqqEdIzNvLJlPMlMDKVqzmEo2Uxq4W6sgmHBRyfa6YG8QWaqfaQ1nnH.9XDTe6HT5NRv_KrqLqdH5YESdRfveE32teBbBh3sWhj2q.i0kbnYCgqBoOfbUnUx9uKxOQkR_ESbYM0P8pLMyepDTiUqZO5.QltBevlbUEnxoaxoN2dgtfbclJEkc5g; vkst=key.67762110-cf11-4d43-b80c-ad8fa902f367.1762204145903.281084a19b1cf63845e3dbca2dae6698517814739385ea25e0df367a8d4195d8";
        return cfg;
    }

public:
    std::string Generate() {
        auto config = CreateConfig();
        std::string response = NetworkOps::ConnectionManager::PerformPostRequest(
            "https://key.valex.io/api/keyauth/generate-direct", 
            "{}", 
            config
        );
        return DataProc::ResponseParser::ExtractKeyFromJson(response);
    }
};