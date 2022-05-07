//
// Created by bravo8234 on 26/04/2022.
//

#ifndef EX4_CPP_A_PLAYER_H
#define EX4_CPP_A_PLAYER_H
#pragma once
#include <utility>
#include "stdexcept"
#include "vector"
#include "string"
#include "Game.hpp"
namespace coup{
    class Game;
    class Player{
    public:
        std::string state;
        Game& game;
        std::string nameP;
        std::string roleP;
        int currentCoins;
        std::string lastAction;
        Player(Game& game, std::string name):currentCoins(0), game(game),nameP(std::move(name)),state("alive"){};
        void income();
        void foreign_aid();
        virtual void coup(Player& player);
        int coins()const {return this->currentCoins;};
        std::string name()const{return this->nameP;};
        std::string role()const{return this->roleP;};
        Player& operator=(Player other);

    };
}
#endif //EX4_CPP_A_PLAYER_H
