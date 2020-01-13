#include "Game.h"
#include <iostream>

Game::Game(){
  
  Network::init(sock,server,"0.0.0.0");
  std::cout << "How many Players are going to be playing? ";
  int option;
  std::cin >> option;
  players.resize(option);
  Network::initServer(sock,server,players);
  
  //Playing Loop Call
  Playing();


}

void Game::Playing(){
  //Give each player id
  for(int i = 0; i < players.size();i++){
    int j = i+1;
    send(players[i],&j,sizeof(int),0);
  }
  //Deal Cards
  dealCards();


}

void Game::dealCards(){
  g.d.shuffleDeck();
  for(int i = 1; i <= players.size();i++){
    g.d.dealCards(i);
  }
  for(int i = 0; i < players.size();i++){
    Network::sendGameState(players[i],g);
  }
}