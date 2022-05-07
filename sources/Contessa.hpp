//
// Created by bravo8234 on 26/04/2022.
//

#ifndef EX4_CPP_A_CONTESSA_H
#define EX4_CPP_A_CONTESSA_H
#include "Player.hpp"
namespace coup{
    class Contessa: public Player{


    public:
        Contessa(Game& game, std::string name);
        static void block(Player& player);
    };
}
#endif //EX4_CPP_A_CONTESSA_H
