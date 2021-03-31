#include "Player.h"
using namespace std;
#include <iostream>
#include <vector>
Player::Player()
{   
    myServ.reserve(4);
    for(int i = 0; i<MAXSERVANT;i++)
    {
        ServantStatus[i] = false;
    }
}
Player::Player(string newName)
{
    name = newName;    
    for(int i = 0; i<MAXSERVANT;i++)
    {
        ServantStatus[i] = false;
    }
}

string Player::getName(){
    return name;
}

// int Player::getLevel()
// {
//     return level;
// }

vector<Servant> Player::getServant()
{
    vector<Servant> temp;
    for(int i =0; i<MAXSERVANT ; i++)
    {
        temp.push_back(myServ[i]);
    }
    return temp;   
}
vector<short> Player::getServantStatus()
{
    vector<short> temp;
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

// void Player::setLevel(short newLevel)
// {
//     level = newLevel;
// }

void Player::setServantStatus(int point, short status)
{
    ServantStatus[point] = status;
}

void Player::setServant(vector<Servant> newServant)
{
    
    myServ = newServant;
    for(int i =0;i<newServant.size();i++)
    {
        ServantStatus[i] = 1;
    }
    // short point = 10;
    // for(int i=0;i<MAXSERVANT;i++)
    // {
    //     if(ServantStatus[i]==0){
    //         point = i;
    //         break;
    //     }
    // }
    // if(point > MAXSERVANT)
    // {
    //     cout << "not empty!!" << endl;        
    // }else{
    //     myServ[point] = newServant;
    // }
}