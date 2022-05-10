#include "Ambassador.hpp"

#include <utility>
namespace coup{
    void Ambassador::transfer(Player &takeFrom, Player &giveTo) {
        this->game.checkTurn(*this);
        //check if the player can do this action
        if(this->currentCoins >= MUST_COUP)
        {
            throw std::logic_error("more then 10 coins, must coup");
        }
        //check if there are coins to transfer
        if(takeFrom.coins() == 0)
        {
            throw std::logic_error("no coins to transfer");
        }
        //transfer the coins
        takeFrom.currentCoins-= 1;
        giveTo.currentCoins +=1;
        this->lastAction = "transfer";
        this->game.moveTurn();

    }
    void Ambassador::block(Player &player) {
        // block a steal action of a captain
        // check if the role of the player is a captain and if there was a steal action to block
        if(player.roleP != "Captain")
        {
            throw std::logic_error("can only block captain");
        }
        if(player.lastAction.rfind("steal",0) != 0)
        {
            throw std::logic_error("can only block steal");
        }
        //using the syntax I wrote to find the amount stolen from the player
        int amountStolen = player.lastAction.at(INDEX_OF_STEAL_AMOUNT) - '0';
        player.currentCoins -= amountStolen;
        std::vector<Player*> players = this->game.getPlayers();
        for(auto& play: players)
        {
            //finding the player that the money was stolen from
            std::string playerName = player.lastAction.substr(INDEX_OF_STEAL_NAME);
            if(play->nameP == playerName)
            {
                play->currentCoins += amountStolen;
                break;
            }
        }
    }

    Ambassador::Ambassador(Game &game, std::string name) : Player(game, std::move(name)) {
        if(this->game.players().empty())
        {
            this->game.currentPlayer = this->nameP;
        }
        this->roleP = "Ambassador";
        game.addPlayer(*this);

    }
}
