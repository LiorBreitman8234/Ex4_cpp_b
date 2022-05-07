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
        if(player.lastAction != "foreign_aid")
        {
            throw std::logic_error("no action to block");
        }
        player.currentCoins -= 2;
    }

    void Duke::tax() {
        this->game.checkTurn(*this);
        this->currentCoins += 3;
        this->game.moveTurn();
        this->lastAction = "tax";
    }
}

