//
// Created by bravo8234 on 26/04/2022.
//

#ifndef EX4_CPP_A_DUKE_H
#define EX4_CPP_A_DUKE_H
#include "Player.hpp"
namespace coup{
    class Duke: public Player{


    public:
        Duke(Game& game, std::string name);
        void block(Player& player);
        void tax();
    };
}
#endif //EX4_CPP_A_DUKE_H
