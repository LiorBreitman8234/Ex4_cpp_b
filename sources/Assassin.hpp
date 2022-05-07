//
// Created by bravo8234 on 26/04/2022.
//

#ifndef EX4_CPP_A_ASSASSIN_H
#define EX4_CPP_A_ASSASSIN_H
#include "Player.hpp"
namespace coup{
    class Assassin: public Player{
    public:
        std::string lastKilled;
        Assassin(Game& game, std::string name);
        void coup(Player &player) override;
    };
}
#endif //EX4_CPP_A_ASSASSIN_H
