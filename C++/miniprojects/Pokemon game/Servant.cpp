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

