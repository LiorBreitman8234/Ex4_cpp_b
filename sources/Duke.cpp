#include "Duke.hpp"
namespace coup{
    Duke::Duke(Game &game, std::string name) : Player(game, std::move(name)) {
        if(this->game.players().empty())
        {
            this->game.currentPlayer = this->nameP;
        }
        this->roleP = "Duke";
        game.addPlayer(*this);

    }

    void Duke::block(Player &player) {
        //check if the action is foreign aid
        if(player.lastAction != "foreign_aid")
        {
            throw std::logic_error("no action to block");
        }
        player.currentCoins -= 2;
    }

    void Duke::tax() {
        this->game.checkTurn(*this);
        //check if the player can do this action
        if(this->currentCoins >= MUST_COUP)
        {
            throw std::logic_error("more then 10 coins, must coup");
        }
        this->currentCoins += TAX;
        this->game.moveTurn();
        this->lastAction = "tax";
    }
}

