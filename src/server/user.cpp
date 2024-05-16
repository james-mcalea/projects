#include "user.h"

User::User()
    : m_level(Bronze),
      m_id(0)
{

}

void User::addAttempt()
{
    m_userFailedAttempts.push_back(UserAuthAttempt());
}
void User::popAttempt()
{
    if (!m_userFailedAttempts.empty())
    {
        m_userFailedAttempts.pop_back();
    }
}

void User::setUserLevel( UserLevel newLevel )
{
    m_level = newLevel;
}

void User::setUserState ( UserState state )
{
    m_state = state;
}

UserLevel User::getUserLevel()
{
    return m_level;
}
UserState User::getUserState()
{
    return m_state;
}

int User::getUserUID()
{
    return m_id;
}

void User::setUserUID( int id )
{
    m_id = id;
}


int User::getNoOfAttempts()
{
    return m_userFailedAttempts.size();
}

std::string User::getUserDetails()
{
    return m_username;
}
