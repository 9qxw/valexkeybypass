#include "ui/WindowManager.cpp"

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    ApplicationWindow app;
    if (!app.Setup()) {
        return -1;
    }
    
    app.Run();
    
    curl_global_cleanup();
    return 0;
}