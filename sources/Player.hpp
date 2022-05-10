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
#define COUP 7
#define MUST_COUP 11
#define ASSASSINATION 3
#define TAX 3
#define INDEX_OF_STEAL_AMOUNT 6
#define INDEX_OF_STEAL_NAME 19
namespace coup{
    class Game;
    class Player{
    public:
        std::string state;//used to check if the player is assassinated or alive (killed players are removed)
        Game& game;
        std::string nameP;//used to check the current turn in the game
        std::string roleP;//used to check the role of the player
        int currentCoins;
        std::string lastAction;//used to check if the action can be manipulated or not
        Player(Game& game, std::string name):currentCoins(0), game(game),nameP(std::move(name)),state("alive"){};
        void income();
        void foreign_aid();
        virtual void coup(Player& player);
        int coins()const {return this->currentCoins;};
        std::string name()const{return this->nameP;};
        std::string role()const{return this->roleP;};
        Player& operator=(const Player& other);
        void setState(const std::string& stateNew);

    };
}
#endif //EX4_CPP_A_PLAYER_H
