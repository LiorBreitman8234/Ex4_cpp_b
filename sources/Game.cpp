#include "Game.hpp"
namespace coup{

    void Game::checkTurn(const Player &player) const {
        if(this->currentPlayer != player.nameP)
        {
            throw std::logic_error("wrong player turn");
        }

    }

    void Game::killPlayer(Player &player) {
        for(size_t i =0; i < this->gamePlayers.size();i++)
        {
            if(gamePlayers.at(i)->nameP == player.nameP)
            {
                this->gamePlayers.erase(gamePlayers.begin()+(long)i, gamePlayers.begin()+(long)i+1);
            }
        }
        this->countPlayers--;
    }

    std::vector<std::string> Game::players() {
        std::vector<std::string> names;
        for(const auto & gamePlayer : this->gamePlayers)
        {
            if(gamePlayer->state == "alive")
            {
                names.push_back(gamePlayer->nameP);
            }
        }
        return names;
    }

    std::string Game::turn() {
        std::string turn;
        for(auto & p: this->gamePlayers)
        {
            if(p->nameP == this->currentPlayer)
            {
                turn = p->nameP;
                return p->nameP;
            }
        }
        return turn;
    }

    Game &Game::operator=(const Game& other) {
        for(const auto & gamePlayer : other.gamePlayers)
        {
            this->gamePlayers.push_back(gamePlayer);
        }
        this->currentPlayer = other.currentPlayer;
        this->currentTurn = other.currentTurn;
        this->countPlayers = other.countPlayers;
        return *this;
    }

    void Game::moveTurn() {

        for(size_t i =0; i < this->gamePlayers.size();i++)
        {
            if(this->currentPlayer == this->gamePlayers.at(i)->nameP)
            {

                if(i == this->gamePlayers.size() - 1)
                {
                    if(this->gamePlayers.at(0)->state.rfind("assassinated",0) == 0)
                    {
                        currentPlayer = this->gamePlayers.at(1)->nameP;
                    }
                    else
                    {
                        currentPlayer = this->gamePlayers.at(0)->nameP;

                    }
                }
                else
                {
                    if(this->gamePlayers.at(i+1)->state.rfind("assassinated",0) == 0)
                    {
                        if(i + 2 <= this->gamePlayers.size() -1)
                        {
                            currentPlayer = this->gamePlayers.at(i+2)->nameP;
                        }
                        else
                        {
                            currentPlayer = this->gamePlayers.at(0)->nameP;
                        }
                    }
                    else
                    {
                        currentPlayer = this->gamePlayers.at(i+1)->nameP;
                    }
                }
                return;
            }
        }
    }

    void Game::addPlayer(Player& player) {
        this->gamePlayers.push_back(&player);
        this->countPlayers += 1;
    }

    std::string Game::winner() {
        int aliveCounter = 0;
        for(auto & player: this->gamePlayers)
        {
            if(player->state == "alive")
            {
                aliveCounter+=1;
            }
        }
        if(aliveCounter != 1)
        {
            throw std::logic_error("more the 1 player");
        }
        return this->gamePlayers.at(0)->nameP;
    }

    std::vector<Player*> Game::getPlayers() {
        return this->gamePlayers;
    }

}