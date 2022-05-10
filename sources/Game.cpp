#include "Game.hpp"
namespace coup{

    void Game::checkTurn(const Player &player) const {
        //this function is used to check whether the right player tried to do a move
        // or if the game has enough players to start
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
        /*
         * this function is used to remove players that were the target of a coup
         * or were assassinated and can't come back
         */
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
        // return all the names of all the players that are alive
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

    Game &Game::operator=(const Game& other) {
        //used to copy a game in the player
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
        /*
         * to move turn to determine which player is playing now
         */
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
                    // if the player is assassinated, go past him
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
        //adding a new player to the game
        // checking all the conditions (max players, if the game started already)
        if(this->gamePlayers.size() == MAX_PLAYERS)
        {
            throw std::logic_error("cant have more then 6 players");
        }
        if(this->isStarted)
        {
            throw std::logic_error("cant add players in the middle of the game");

        }
        this->gamePlayers.push_back(&player);
        this->countPlayers += 1;
    }

    std::string Game::winner() {
        //used to determine the winner of the game
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
        //function for any_of
        return toFind == toCheck.nameP && toCheck.state == "alive";
    }
    bool Game::checkInGame(Player& player) {
        // check if a player is in the game and alive
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