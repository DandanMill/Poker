#include "Game.h"
#include <iostream>

Game::Game(){
  
  Network::init(sock,server,"0.0.0.0");
  std::cout << "How many players are going to be playing? ";
  int option;
  std::cin >> option;
  conns.resize(option);
  players.reserve(option);
  /*for(int i = 0; i < players.capacity();i++){
    players.emplace_back(Player());
  }*/
  Network::initServer(sock,server,conns);
  
  //Playing Loop Call
  Playing();

  close(sock);
}

void Game::Playing(){
  //Give each player id
  for(int i = 0; i < conns.size();i++){
    int j = i + 1;
    send(conns[i],&j,sizeof(j),0);
  }
  //Deal Cards------------------------------------------
  dealCards();
  //First round of betting-----------------------------
  getBets();
  for(int i = 0; i < conns.size();i++){
    std::cout << "Player number " << players[i].getId() << "'s bet " <<  players[i].getBet() << std::endl;
  }
  std::cout << "Pot is: " << pot << std::endl;
  //Second round of betting-------------------------------
  std::cout << "Round 2" << std::endl;
  g.maxBet = 0;
  getBets();
  for(int i = 0; i < conns.size();i++){
    std::cout << "Player number " << players[i].getId() << "'s bet " <<  players[i].getBet() << std::endl;
  }
  std::cout << "Pot is: " << pot << std::endl;
}

void Game::getBets(){
  for(int i = 0; i < conns.size();i++){
    Network::sendGameState(conns[i],g);
    Network::recvGameState(conns[i],g);
    players[i] = g.players;
    pot += players[i].getBet();
  }
}

void Game::dealCards(){
  g.d.shuffleDeck();
  for(int i = 1; i <= conns.size();i++){
    g.d.dealCards(i);
  }
  for(int i = 0; i < conns.size();i++){
    Network::sendGameState(conns[i],g);
  }
}