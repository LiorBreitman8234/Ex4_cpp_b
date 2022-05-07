#include "Assassin.hpp"
namespace coup{
    void Assassin::coup(Player &player) {
        this->game.checkTurn(*this);
        std::vector<Player*> players = this->game.getPlayers();
        for(auto & playerV : players)
        {
            // removing the players assassinated by this player from the game
            if(playerV->state == "assassinated by " + this->nameP)
            {
                this->game.killPlayer(*playerV);
            }
        }
        if(this->currentCoins < 3)
        {
            throw std::logic_error("cant assassinate with less then 3 coins");
        }
        if(this->currentCoins > 6)
        {
            this->currentCoins -= 7;
            this->lastAction = "kill";
            this->lastKilled = player.nameP;
        }
        else
        {
            this->currentCoins -= 3;
            this->lastAction = "assassination";
            this->lastKilled = player.nameP;
            player.state = "assassinated by " + this->nameP;
        }
        this->game.moveTurn();


    }

    Assassin::Assassin(Game &game, std::string name) : Player(game, std::move(name)) {
        if(this->game.players().empty())
        {
            this->game.currentPlayer = this->nameP;
        }
        this->roleP = "Assassin";
        game.addPlayer(*this);

    }
}