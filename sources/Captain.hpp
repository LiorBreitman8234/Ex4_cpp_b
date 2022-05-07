//
// Created by bravo8234 on 26/04/2022.
//

#ifndef EX4_CPP_A_CAPTIAN_H
#define EX4_CPP_A_CAPTIAN_H
#include "Player.hpp"
namespace coup{
    class Captain: public Player{

    public:
        Captain(Game& game, std::string name);
        void steal(Player& player);
        void block(Player& player);
    };
}
#endif //EX4_CPP_A_CAPTIAN_H
