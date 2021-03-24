#ifndef SERVANT_H_INCLUDED
#define SERVANT_H_INCLUDED

#include <string>
#include <vector>
class Servant{
    private:
        std::string name;
        float hitPoints;
        int level;
        std::string skills[4];
        int skillLevels[4];
    
    public:
        Servant();

        std::vector <int> getSkillLevels();
        std::vector <std::string> getSkills();
        std::string getName();
        void setName(std::string name);
        void setSkills(std::string skills,int points);
        int getHitPoints();
       // void isAttackedByAnotherPokemonSkillPoints(int skillPoint);
        
};

#endif