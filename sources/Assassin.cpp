#include "Assassin.hpp"
namespace coup{
    void Assassin::coup(Player &player) {
        this->game.checkTurn(*this);
        std::vector<Player*> players = this->game.getPlayers();
        for(auto & playerV : players)
        {
            // removing the players assassinated by in the last round this player from the game
            if(playerV->state == "assassinated by " + this->nameP)
            {
                this->game.killPlayer(*playerV);
            }
        }
        if(!this->game.checkInGame(player))
        {
            throw std::logic_error("player assassinated or killed already");
        }
        if(this->currentCoins < ASSASSINATION)
        {
            throw std::logic_error("cant assassinate with less then 3 coins");
        }
        if(this->currentCoins >= COUP)
        {
            this->currentCoins -= COUP;
            this->lastAction = "kill";
            this->lastKilled = player.nameP;
            this->game.killPlayer(player);
        }
        else
        {
            this->currentCoins -= ASSASSINATION;
            this->lastAction = "assassination";
            this->lastKilled = player.nameP;
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