#include "Ambassador.hpp"

#include <utility>
namespace coup{
    void Ambassador::transfer(Player &takeFrom, Player &giveTo) {
        this->game.checkTurn(*this);
        if(this->currentCoins >= MUST_COUP)
        {
            throw std::logic_error("more then 10 coins, must coup");
        }
        if(takeFrom.coins() == 0)
        {
            throw std::logic_error("no coins to transfer");
        }
        takeFrom.currentCoins-= 1;
        giveTo.currentCoins +=1;
        this->lastAction = "transfer";
        this->game.moveTurn();

    }
    void Ambassador::block(Player &player) {
        if(player.roleP != "Captain")
        {
            throw std::logic_error("can only block captain");
        }
        if(player.lastAction.rfind("steal",0) != 0)
        {
            throw std::logic_error("can only block steal");
        }
        int amountStolen = player.lastAction.at(INDEX_OF_STEAL_AMOUNT) - '0';
        player.currentCoins -= amountStolen;
        std::vector<Player*> players = this->game.getPlayers();
        for(auto& play: players)
        {
            std::string playerName = player.lastAction.substr(INDEX_OF_STEAL_NAME);
            if(play->nameP == playerName)
            {
                play->currentCoins += amountStolen;
                break;
            }
        }
        this->lastAction = "block";
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
