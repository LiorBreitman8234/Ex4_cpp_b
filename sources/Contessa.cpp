#include "Contessa.hpp"
#include "Assassin.hpp"

namespace coup
{
    Contessa::Contessa(Game &game, std::string name) : Player(game, std::move(name)) {
        if(this->game.players().empty())
        {
            this->game.currentPlayer = this->nameP;
        }
        this->roleP ="Contessa";
        game.addPlayer(*this);

    }

    void Contessa::block(Player &player) {
        /*
         * check if the player is an assassin and his last action is actually assassination
         */
        if(player.roleP != "Assassin"){
            throw std::logic_error("cant stop player that is not assassin");
        }
        if(player.lastAction != "assassination")
        {
            throw std::logic_error("no coup to block");
        }
        std::vector<Player*> players = this->game.getPlayers();
        for(auto & playerV : players)
        {
            // setting the state of the player assassinated to alive,so he can play
            if(playerV->state == "assassinated by "+ player.nameP)
            {
                playerV->setState("alive");
            }
        }
    }
}
