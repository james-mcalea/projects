#ifndef USER_UTILS_H
#define USER_UTILS_H


#include <chrono>
#include <vector>


enum UserState
{
    Locked,
    Unlocked
};

enum UserLevel
{
    Bronze,
    Silver,
    Gold,
    Diamond
};

struct UserAuthAttempt
{
    std::chrono::time_point<std::chrono::system_clock> creationTime;
    UserAuthAttempt() : creationTime(std::chrono::system_clock::now()) {}
};



#endif // USER_UTILS_H
