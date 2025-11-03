#include "../core/NetworkOperations.hpp"
#include "../core/DataProcessing.hpp"

class ExternalKeyGenerator {
private:
    NetworkOps::HttpConfig CreateConfig() {
        NetworkOps::HttpConfig cfg;
        cfg.userAgent = "Mozilla/5.0 (X11; Linux x86_64; rv:144.0) Gecko/20100101 Firefox/144.0";
        cfg.headers = {
            "Accept: application/json",
            "Accept-Language: en-US,en;q=0.5",
            "Accept-Encoding: gzip, deflate, br, zstd",
            "Referer: https://extkey.valex.io/ext-key-system",
            "Content-Type: application/json",
            "Origin: https://extkey.valex.io",
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
        cfg.cookieData = "vkst_ext=ext.0fb528ac-0197-4e4e-b547-427204841f57.1751651820494.c4acd29e46d5690c82993d238d86dac3575151a00288648e750221ae441274f3; cf_clearance=3D1c77UMmPN1HAmUEUmikdgmGvqSZkidjLv4iLXhSQc-1761651263-1.2.1.2-d84A6Fx8nUisKMgreI9TInmD6iVM32Ktq9AluA4BwCg7aPYIqP_2zTBskSybeH.uW_g0Yl.A0jMX6H5A5oywBMawFd_z74CcrecOdkOciUUoPFpkoDtM8ZHpTpz5sQPmItFwkiqtovu8EsEbr8bgC7pEbdcXPvyMmXt4HeOzupVB.vD4RoWRnbhyyun3.ePINlCf8tnMh3Y51RkglZRFGQWysvEzhZtHwhCDDKeRVCw; cf_cfl_rc_ni=1; cf_clearance=WrpL4IoJ_ArIFp62kF8rnd65jyW34c7DJJkQnZa.BdU-1762203780-1.2.1.1-XfBpwrWFClA1awLeU3rOR5bnW5r3k0Q3ubKw1pGHdnfURwpQeyPypqqEdIzNvLJlPMlMDKVqzmEo2Uxq4W6sgmHBRyfa6YG8QWaqfaQ1nnH.9XDTe6HT5NRv_KrqLqdH5YESdRfveE32teBbBh3sWhj2q.i0kbnYCgqBoOfbUnUx9uKxOQkR_ESbYM0P8pLMyepDTiUqZO5.QltBevlbUEnxoaxoN2dgtfbclJEkc5g; vkst_ext=ext.31038e89-85bc-4204-97ab-d89f55e863b1.1762203724899.d0290e32ae22e30f906a2b9bb85b4eb0f7a7db7dd1f0980d5f052fcfed0d4d67";
        return cfg;
    }

public:
    std::string Generate() {
        auto config = CreateConfig();
        std::string response = NetworkOps::ConnectionManager::PerformPostRequest(
            "https://extkey.valex.io/api/ext-keyauth/generate-direct", 
            "{}", 
            config
        );
        return DataProc::ResponseParser::ExtractKeyFromJson(response);
    }
};