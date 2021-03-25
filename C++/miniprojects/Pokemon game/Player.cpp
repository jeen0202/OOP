#include "Player.h"
using namespace std;
#include <iostream>
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

void Player::setLevel(short newLevel)
{
    level = newLevel;
}

void Player::setServantStatus(int point, short status)
{
    ServantStatus[point] = status;
}

void Player::setServant(Servant newServant)
{
    short point = 10;
    for(int i=0;i<MAXSERVANT;i++)
    {
        if(ServantStatus[i]==0){
            point = i;
            break;
        }
    }
    if(point > MAXSERVANT)
    {
        cout << "not empty!!" << endl;        
    }else{
        myServ[point] = newServant;
    }
}