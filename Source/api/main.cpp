#include "CivetServer.h"
#include "api_handler.cpp"

#include <chrono>
#include <thread>
int main() {
    CivetServer server({
        "document_root", ".",
        "listening_ports", "8080",
    });

    // Add your API handler
    server.addHandler("/api", new MyApiHandler);

    while (true) {
        // Keep the server running
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
