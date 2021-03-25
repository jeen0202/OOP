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
        short ServantStatus[MAXSERVANT];
    public:
        Player();
        Player(std::string name, short level);
        std::string getName();
        int getLevel();
        std::vector<Servant> getServant();
        std::vector<short> getServantStatus();
        void setName(std::string newName);
        void setLevel(short newLevel);
        void setServantStatus(int point, short status);
        void setServant(Servant newServant);
};

#endif