#ifndef SKILL_H_INCLUDED
#define SKILL_H_INCLUDED

#include<string>

class Skill{
    private:
        std::string name;
        short level;
        float damage;
        float accuracy;
    public:        
        Skill();        
        Skill(std::string name,float dmg, float acc, short level = 1 );
        std::string getName();
        short getLevel();
        float getDamage();
        float getAccuracy();
        void setName(std::string newName);
        void setLevel(short newLevel);
        void setDamage(float newDamage);
        void setAccuracy(float newAccuracy);
        std::string toString();
};

#endif