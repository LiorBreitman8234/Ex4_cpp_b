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
        if(this->currentCoins < ASSASSINATION)
        {
            throw std::logic_error("cant assassinate with less then 3 coins");
        }
        if(this->currentCoins >= COUP)
        {
            this->currentCoins -= COUP;
            this->lastAction = "kill";
            this->currentCoins-=3;
            this->lastKilled = player.nameP;
        }
        else
        {
            this->currentCoins -= ASSASSINATION;
            this->lastAction = "assassination";
            this->lastKilled = player.nameP;
            this->currentCoins -=3;
            player.setState("assassinated by " + this->nameP);
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