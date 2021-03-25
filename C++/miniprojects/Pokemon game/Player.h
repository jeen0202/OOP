#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#define MAXSERVANT 3

#include "Servant.h"

#include<vector>

class Player{
    private:
        std::string name;
        short level;
        Servant myServ[MAXSERVANT];
        bool ServantStatus[MAXSERVANT];
    public:
        Player();
        std::string getName();
        int getLevel();
        std::vector<Servant> getServant();
        std::vector<bool> getServantStatus();
        void setName(std::string newName);
        void setLevel(short newLevel);
        void setServantStatus(int point, bool status);
        void setServant(Servant newServant);
};

#endif