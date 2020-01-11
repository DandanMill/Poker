#include "Game.h"
#include <utility>
#include <iostream>


//Constructor
Game::Game(){
  std::cout << "How many Players will be playing";
  int option;
  std::cin >> option;
  players.resize(option);
  gameStates.resize(option);
  Network::init(sock,server,"0.0.0.0");
  Network::initServer(sock,server,players);
  Playing();

  close(sock);
  
}

void Game::dealCards(){
  for(int i = 0; i < players.size();i++){
    std::cout << "Dealing cards to player number " << i << std::endl;
    d.dealCards(i+1);
    d.showHand(i+1);
  }
  for(int i = 0; i < players.size();i++){
    d.getState(i+1,g);
    Network::sendGameState(players[i],g);
  }
}

//Playing loop
void Game::Playing(){
    std::cout << "Shuffling Deck\n";
    d.shuffleDeck();
    dealCards();
    getBets();
    std::cout << "Pot is " << pot << std::endl;
    shuffleDeck();

}

void Game::shuffleDeck(){
  for(int i = 0; i < players.size();i++){
    Network::recvGameState(players[i],g);
  }
}

void Game::getBets(){
  for(int i = 0; i < players.size();i++){
    Network::sendGameState(players[i],g);
    Network::recvGameState(players[i],g);
    pot +=  g.bet;
  }
}
 /*
  //Shuffles deck
  d.shuffleDeck();
  //Resets called and folded booleans
  for(int i = 0;i < players.size();i++){
    players[i].resetCF();
  }
  //Deals cards to every player and prints them
  for(int i = 0; i <  players.size();i++){
    d.dealCards(players[i].getId());
    std::cout << "Player " << players[i].getId() << " Cards\n";
    d.showHand(players[i].getId());
  }
  //Round of betting
  Round();
  //Switch cards for players who didn't fold
  for(int i = 0;i<players.size();i++){
    if(players[i].getFolded() == false){
      switchCards(players[i].getId());
      d.showHand(players[i].getId());
      players[i].setCalled(false);  
    }
  }
  //Round of betting
  Round();

  //Check who won and change money depending on
  int win = checkWon();
  players[win-1].setMoney(players[win-1].getMoney() + pot);
  for(int i = 0; i < players.size();i++){
    std::cout << "Player " << players[i].getId() << "'s Money" << players[i].getMoney() << std::endl;
  }*/

//Gets all players bets
/*int Game::getAllBets(){
  int ret = 0;
  for(int i = 0; i < players.size();i++){
    ret += players[i].getBet();
  }
  return ret;
}
//Betting round
void Game::Round(){
  for(int i = 0; i < players.size(); i++){
    players[i].setBet(0);
  }
  int maxBet = 0;
  int index = 0;
  while(isCalled() == false){
    maxBet = players[index].Play(maxBet);
    isPCalled(maxBet);
    index++;
    if(index >= players.size()){
      index = 0;
    }
  }
  for(int i = 0; i < players.size(); i++){
    players[i].setMoney(players[i].getMoney() - players[i].getBet()); 
  }
  pot += getAllBets();
}


//Switch cards function
void Game::switchCards(int player){
    int numSwitch = 0;
    std::cout << "How many cards do you want to switch?";
    std::cin >> numSwitch;
    d.switchCard(player,numSwitch);

}
//Check who has the best hand
int Game::checkWon(){
   int cardCount = -1;
   int winning = 1;
   for(int i = 0;i< players.size();i++){
     if(players[i].getCalled() == true && players[i].getFolded() == false){
        if(cardCount < d.checkHand(players[i].getId())){
          std::cout << "Player " << players[i].getId() << " CardCount " <<  d.checkHand(players[i].getId());
          winning = players[i].getId();
          cardCount = d.checkHand(players[i].getId());
        }
      }
    }
  std::cout << "Player " << winning << " Won" << std::endl;
  return winning;
}
  
//Check if everyone is called
bool Game::isCalled(){
  for(int i = 0; i< players.size();i++){
      if(players[i].getCalled() == false){
        return false;
      }
  }
  return true;
}

//Check if you you're bet is called with the highest bet
void Game::isPCalled(int maxBet){
    for(int i = 0; i < players.size();i++){
      players[i].checkBet(maxBet);
    }
}

*/