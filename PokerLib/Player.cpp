#include "Player.h"
#include <iostream>

Player::Player()
:money(1000),called(false),folded(false),id(0),bet(0)
{}

Player::Player(int _id)
:money(1000),called(false),folded(false),id(_id),bet(0)
{}

Player::Player(int _id,bool _called)
:money(1000),called(_called),folded(false),id(_id),bet(0)
{}

int Player::getId(){
  return id;
}

bool Player::getCalled(){
  return called;
}

void Player::setCalled(bool b){
  called = b;
}

void Player::resetCF(){
  called = false;
  folded = false;
}

bool Player::getFolded(){
  return folded;
}

int Player::getMoney(){
  return money;
}
int Player::getBet(){
  return bet;
}
void Player::setMoney(int _money){
  money = _money;
}

void Player::checkBet(int maxBet){
  if(folded == false){
  if(maxBet > bet){
    called = false;
  }
  }
}

void Player::setBet(int _bet){
  bet = _bet;
}

int Player::Play(int maxBet){
   char option = ' ';
   int raise = 0;
   while(called == false && folded == false){
   std::cout << "Current bet: " << maxBet << std::endl;
   std::cout << "Player number " << id << " 's Turn" << "(C/R/F)\n";
   std::cin >> option;
   switch(option){
     case 'c':
     case 'C':
          called = true;
          bet = maxBet;
          return maxBet;
     case 'r':
     case 'R':
          std::cout << "How much you would you like to raise by: ";
          std::cin >> raise;
          called = true;
          bet = maxBet + raise;
          return maxBet+raise;
     case 'f':
     case 'F':
        folded = true;
        called = true;
        return maxBet;


   }
 }
 return maxBet;
}
