#include "Skill.h"
#include "math.h"
using namespace std;

float presicion(float input)
{
    float temp;
    temp = round(input * 1000.0) / 1000.0;
    return temp;
}

Skill::Skill():level(1){};

Skill::Skill(string newName, float dmg, float acc, short lv)
{
    name = newName;
    damage = dmg;
    accuracy = acc;
    level = lv;
}

string Skill::getName()
{
    return name;
}
void Skill::setName(string newName)
{
    name = newName;
}

short Skill::getLevel()
{
    return level;
}

void Skill::setLevel(short newLevel)
{
    level = newLevel;
}
float Skill::getDamage(){
    return damage;
}

void Skill::setDamage(float newDamage){
    damage = newDamage;
}

float Skill::getAccuracy()
{
    return accuracy;
}

void Skill::setAccuracy(float newAccuracy)
{
    accuracy = newAccuracy;
}
string Skill::toString()
{
    string temp;
    
    temp = name + " " + to_string(level) + " "+ to_string((int)damage) + " " + to_string((int)accuracy) + "\n"; 
    return temp;
}