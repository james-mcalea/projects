#include "server.h"
#include "user.h"
#include "user_utils.h"

#include <iostream>

#include <thread>
#include <chrono>

Server& Server::getInstance()
{
    DEBUG("[%s] \t %s",__func__ ,"Getting instance!");
    static Server instance;
    return instance;
}

Server::Server()
{
    DEBUG("[%s] \t %s",__func__ ,"Create new instance");
}

Server::~Server()
{
    stop();
    if (serverThread.joinable()) {
        serverThread.join();
    }
    DEBUG("[%s] \t %s",__func__ ,"Instance destroyed!");
}

void Server::run()
{
    DEBUG("[%s] \t %s",__func__ ,"Running server!");
    if (!isRunning) {
        isRunning = true;
        serverThread = std::thread([this] { runServer(); });
        serverThread.detach();

    }
}

void Server::stop()
{
    DEBUG("[%s] \t %s",__func__ ,"Stopping instance!");
}

void Server::runServer()
{
    while(1)
    {
        DEBUG("[%s] \t %s",__func__ ,"Tick");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}




int main()
{
    Server& serverInstance = Server::getInstance();
    

    serverInstance.run();

    User myUser;
    myUser.addAttempt();
    myUser.addAttempt();
    myUser.addAttempt();
    myUser.addAttempt();
    int size = myUser.getNoOfAttempts();
    serverInstance.stop();

    std::this_thread::sleep_for(std::chrono::seconds(3));
    DEBUG("[%s] \t %s%d",__func__, "Attempts.size: ", size);
    DEBUG("[%s] \t %s",__func__ ,"Main thread is done");
}