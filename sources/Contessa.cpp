#include "Contessa.hpp"
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
        if(player.roleP != "Assassin"){
            throw std::logic_error("cant stop player that is not assassin");
        }
        if(player.lastAction != "assassination")
        {
            throw std::logic_error("no coup to block");
        }
        player.state = "alive";
    }
}
