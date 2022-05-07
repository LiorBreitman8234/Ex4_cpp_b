//
// Created by bravo8234 on 26/04/2022.
//

#ifndef EX4_CPP_A_GAME_H
#define EX4_CPP_A_GAME_H
#pragma once
#include "iostream"
#include "vector"
#include "Player.hpp"

namespace coup{
    class Player;
    class Game{
    private:
        std::vector<Player*> gamePlayers;
        int countPlayers;
        int currentTurn;
    public:
        std::string currentPlayer;
        Game():gamePlayers(std::vector<Player*>()),countPlayers(0),currentTurn(1){};
        int getTurn() const{return currentTurn;};
        void addPlayer(Player& player);
        void checkTurn(const Player& player) const;
        std::vector<std::string> players();
        void killPlayer(Player& player);
        std::string turn();
        void moveTurn();
        std::string winner();
        Game& operator=(const Game& other);
    };
}
#endif //EX4_CPP_A_GAME_H
