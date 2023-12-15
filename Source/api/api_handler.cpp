#include "CivetServer.h"

class MyApiHandler : public CivetHandler {
public:
    bool handleGet(CivetServer* server, struct mg_connection* conn) override {
        // Handle GET requests here
        mg_printf(conn, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n");
        mg_printf(conn, "Hello from My API!");
        return true;
    }

    bool handlePost(CivetServer* server, struct mg_connection* conn) override {
        // Handle POST requests here
        // Access request data using mg_get_request_info and mg_read
        mg_printf(conn, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n");
        mg_printf(conn, "Received a POST request!");
        return true;
    }
};

