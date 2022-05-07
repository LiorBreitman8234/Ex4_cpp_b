#include "Player.hpp"
namespace coup{

    void Player::coup(Player &player) {
        this->game.checkTurn(*this);
        if(this->currentCoins < 7)
        {
            throw std::logic_error("not enough coins to coup");
        }
        player.state = "dead";
        this->game.killPlayer(player);
        this->game.moveTurn();
    }

    void Player::foreign_aid() {
        this->game.checkTurn(*this);
        this->currentCoins += 2;
        this->lastAction = "foreign_aid";
        this->game.moveTurn();
    }

    void Player::income() {
        this->game.checkTurn(*this);
        this->currentCoins += 1;
        this->lastAction = "income";
        this->game.moveTurn();
    }

    Player &Player::operator=(Player other) {
        this->currentCoins = other.currentCoins;
        this->lastAction = other.lastAction;
        this->state = other.state;
        this->roleP = other.roleP;
        return *this;
    }
}