#include "Player.h"
using namespace std;
#include <vector>
Player::Player()
{
    level = 1;
    for(int i = 0; i<MAXSERVANT;i++)
    {
        ServantStatus[i] = false;
    }
}

string Player::getName(){
    return name;
}

int Player::getLevel()
{
    return level;
}

vector<Servant> Player::getServant()
{
    vector<Servant> temp;
    for(int i =0; i<MAXSERVANT ; i++)
    {
        temp.push_back(myServ[i]);
    }
    return temp;   
}
vector<bool> Player::getServantStatus()
{
    vector<bool> temp;
    for(int i=0; i <MAXSERVANT; i++)
    {
        temp.push_back(ServantStatus[i]);
    }
    return temp;
}

void Player::setName(string newName)
{
    name = newName;
}

void Player::setLevel(short newLevel)
{
    level = newLevel;
}

void Player::setServantStatus(int point, bool status)
{
    ServantStatus[point] = status;
}

void Player::setServant(Servant newServant)
{
    
    for(int i=0;i<MAXSERVANT;i++)
    {
        
    }
}