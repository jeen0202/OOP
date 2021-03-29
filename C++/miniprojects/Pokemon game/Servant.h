#ifndef SERVANT_H_INCLUDED
#define SERVANT_H_INCLUDED

#define MAXSKILL 4

#include "Skill.h"
#include <string>
#include <vector>
class Servant{
    private:
        std::string name;
        float hitPoints;
        int level;
        Skill skills[MAXSKILL];        
    
    public:
        Servant();
        int getLevel();
        std::vector <Skill> getSkills();
        std::string getName();
        int getHitPoints();
        void setLevel(int level);
        void setName(std::string name);        
        void isAttacked(int damage, float acc);
        std::string toString();
        
};

#endif