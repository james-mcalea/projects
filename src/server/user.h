#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "user_utils.h"

class User 
{
    public:

        User();

        void addAttempt();
        void popAttempt();

        void setUserLevel( UserLevel newLevel );
        void setUserState ( UserState state );
        void setUserUID( int id );

        UserLevel getUserLevel();
        UserState getUserState();
        int getUserUID();

        int  getNoOfAttempts();
        std::string getUserDetails();

    private:
        int m_id;
        UserLevel   m_level;
        UserState   m_state;
        std::string m_username;
        std::vector<UserAuthAttempt> m_userFailedAttempts;
};

#endif // USER_H
