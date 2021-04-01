#include "Servant.h"
#include <array>
#include <random>
#include <sstream>
#include <iostream>
using namespace std;

Servant::Servant():hitPoints(100)
{}

string Servant::getName()
{
    return name;
}
int Servant::getLevel()
{
    return level;
}
void Servant::setLevel(int newLevel)
{
    level = newLevel;
}
void Servant::setName(string newName)
{
    name = newName;
}

int Servant::getHitPoints()
{
    return hitPoints;
}

void Servant::isAttacked(Skill sk)
{
    bool result = false;
    float damage = sk.getDamage();
    //난수 생성
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0,100);
    if(dis(gen)<=sk.getAccuracy())
        result = true;

    if(result){
        cout << "명중" << endl;  
        cout << name << " 가 받은피해 : " << damage << endl;
        hitPoints -= damage;
        if (hitPoints<0)
            hitPoints = 0;
        cout << name << "의 잔여 체력 : " << hitPoints << endl;    
    }else{
        cout << "빗나감" << endl;
    }
}

vector<Skill> Servant::getSkills()
{
    return skills;
}
void Servant::setSkills(vector<Skill> newSkills)
{   
    int i;
    skills.clear();
    //cout << newSkills.size() << endl;
    //cout << newSkills[0].toString() << endl;
    // skills.assign(newSkills.begin(),newSkills.end());
    for(i = 0;i<newSkills.size();i++)
    {
            //cout << "push "<<i << endl;        
           skills.emplace_back(newSkills.at(i));
    }
    // for(i = 0;i<skills.size();i++)
    // {
    //     cout << skills.at(i).toString() ;
    // }
}

string Servant::toString()
{
    string str;
    str = name + " " + to_string(level) + " " + to_string(hitPoints) ;
    return str;
}
void Servant::setHitPoints(float newbattle)
{
    hitPoints = newbattle;
}