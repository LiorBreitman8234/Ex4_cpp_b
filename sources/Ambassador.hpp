//
// Created by bravo8234 on 26/04/2022.
//

#ifndef EX4_CPP_A_AMBASSADOR_H
#define EX4_CPP_A_AMBASSADOR_H
#include "Player.hpp"
namespace coup{
    class Ambassador : public Player{
    public:
        Ambassador(Game & game, std::string name);
        void block(Player& player);
        void transfer(Player& takeFrom, Player& giveTo);
    };
}


#endif //EX4_CPP_A_AMBASSADOR_H
