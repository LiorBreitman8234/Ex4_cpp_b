#include "Captain.hpp"

#include <utility>

namespace coup {
    void Captain::block(Player &player) {
        this->game.checkTurn(*this);
        if (player.roleP != "Captain") {
            throw std::logic_error("can only block a captain");
        }
        if (player.lastAction == "steal") {
            player.currentCoins -= 2;
        }
    }

    void Captain::steal(Player &player) {
        this->game.checkTurn(*this);
        switch (player.currentCoins) {
            case 1:
                this->currentCoins += 1;
                player.currentCoins -=1;
                break;
            case 0:
                break;
            default:
                this->currentCoins += 2;
                player.currentCoins -=2;
                break;
        }
        this->lastAction = "steal";
        this->game.moveTurn();

    }

    Captain::Captain(Game &game, std::string name) : Player(game, std::move(name)) {
        if(this->game.players().empty())
        {
            this->game.currentPlayer = this->nameP;
        }
        this->roleP = "Captain";
        game.addPlayer(*this);
    }
}