#include "Servant.h"
#include <array>
#include <random>
#include <sstream>

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

void Servant::isAttacked(int damage, float acc)
{
    bool result = false;
    //난수 생성
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0,9);
    if(dis(gen)<=acc)
        result = true;

    if(result){    
        hitPoints -= damage;
        if (hitPoints<0)
            hitPoints = 0;
    }
}

vector<Skill> Servant::getSkills()
{
    vector<Skill> temp;
    for(int i =0;i<(sizeof(skills)/sizeof(string));i++)
    {
        temp.push_back(skills[i]);
    };
    return temp;
}
void Servant::setSkills(vector<Skill> newSkills)
{
    for(int i = 0;i<newSkills.size();i++){        
            skills.push_back(newSkills[i]);
    }
}

string Servant::toString()
{
    string str;
    str = name + " " + to_string(level) + " " + to_string(hitPoints) ;
    return str;
}

