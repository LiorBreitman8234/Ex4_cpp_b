//
// Created by bravo8234 on 26/04/2022.
//

#ifndef EX4_CPP_A_GAME_H
#define EX4_CPP_A_GAME_H
#pragma once
#include "iostream"
#include "vector"
#include "Player.hpp"
#include <algorithm>
#define MAX_PLAYERS 6

namespace coup{
    class Player;
    class Game{
    private:
        std::vector<Player*> gamePlayers;
        int countPlayers;
        int currentTurn;
        bool isStarted;
    public:
        std::string currentPlayer;
        Game():gamePlayers(std::vector<Player*>()),countPlayers(0),currentTurn(1),isStarted(false){};
        bool checkInGame(Player& player);
        int getTurn() const{return currentTurn;};
        static bool checkNameAndState(const std::string& toFind,Player& toCheck);
        void addPlayer(Player& player);
        void checkTurn(const Player& player) const;
        std::vector<std::string> players();
        void killPlayer(Player& player);
        std::string turn();
        void moveTurn();
        std::string winner();
        std::vector<Player*> getPlayers();
        Game& operator=(const Game& other);
    };
}
#endif //EX4_CPP_A_GAME_H
