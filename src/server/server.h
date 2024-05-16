#include <thread>
#include <atomic>
#ifndef SERVER_H
#define SERVER_H

#if 1
#define DEBUG(format, ...) std::printf(format "\n", __VA_ARGS__)
#else
#define DEBUG(...)
#endif


class Server
{
    public:
        static Server& getInstance();
        void run();
        void stop();


    private:
        std::thread serverThread;
        std::atomic<bool> isRunning;

        Server();
        ~Server();
        Server(const Server&) = delete;
        Server& operator=(const Server&) = delete;

        static void runServer();
};

#endif // SERVER_H