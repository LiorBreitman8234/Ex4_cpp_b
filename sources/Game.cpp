#include "Game.hpp"
namespace coup{

    void Game::checkTurn(const Player &player) const {
        if(this->gamePlayers.size() <= 2 && this->currentTurn == 1)
        {
            throw std::logic_error("not enough players");
        }
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
        if(!this->isStarted)
        {
            this->isStarted = true;
        }
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
                        this->currentTurn++;
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
                            this->currentTurn++;
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
        if(this->gamePlayers.size() == MAX_PLAYERS)
        {
            throw std::logic_error("cant have more then 6 players");
        }
        if(this->isStarted)
        {
            throw std::logic_error("cant had players in the middle of the game");

        }
        this->gamePlayers.push_back(&player);
        this->countPlayers += 1;
    }

    std::string Game::winner() {
        if(this->currentTurn == 1)
        {
            throw std::logic_error("game didnt start");
        }
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
            throw std::logic_error("more then 1 player alive");
        }
        for(auto & player: this->gamePlayers)
        {
            if(player->state == "alive")
            {
                return player->nameP;
            }
        }
        return this->gamePlayers.at(0)->nameP;
    }

    std::vector<Player*> Game::getPlayers() {
        return this->gamePlayers;
    }
    bool Game::checkNameAndState(const std::string& toFind,Player& toCheck){
        return toFind == toCheck.nameP && toCheck.state == "alive";
    }
    bool Game::checkInGame(Player& player) {
        //return std::any_of(this->gamePlayers.begin(),this->gamePlayers.end(),[&player](Player play){return checkNameAndState(player.nameP,play);});
        for(auto &play:this->gamePlayers)
        {
            if(checkNameAndState(player.nameP,*play))
            {
                return true;
            }
        }
        return false;
    }

}