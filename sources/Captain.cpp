#include "Captain.hpp"

#include <utility>

namespace coup {
    void Captain::block(Player &player) {
        this->game.checkTurn(*this);
        if (player.roleP != "Captain") {
            throw std::logic_error("can only block a captain");
        }
        if (player.lastAction.rfind("steal",0) == 0) {
            int amountStolen = player.lastAction.at(INDEX_OF_STEAL_AMOUNT) - '0';
            player.currentCoins -= amountStolen;
            for(auto& play: this->game.getPlayers())
            {
                if(play->nameP == player.lastAction.substr(INDEX_OF_STEAL_NAME))
                {
                    play->currentCoins += amountStolen;
                    break;
                }
            }
        }
        throw std::logic_error("can only block steal");
    }

    void Captain::steal(Player &player) {
        this->game.checkTurn(*this);
        if(this->currentCoins >= MUST_COUP)
        {
            throw std::logic_error("more then 10 coins, must coup");
        }
        switch (player.currentCoins) {
            case 1:
                this->currentCoins += 1;
                player.currentCoins -=1;
                this->lastAction ="steal 1 coins from "+ player.nameP;
                break;
            case 0:
                this->lastAction ="steal 0 coins from "+ player.nameP;
                break;
            default:
                this->currentCoins += 2;
                player.currentCoins -=2;
                this->lastAction ="steal 2 coins from "+ player.nameP;
                break;
        }

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