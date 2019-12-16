#include "Player.h"
#include <iostream>

Player::Player(int _id){
  money = 1000;
  called = false;
  folded = false;
  id = _id;

}

int Player::getId(){
  return id;
}

bool Player::getCalled(){
  if(!called && !folded){
    return false;
  }
  else{
    return true;
  }
}

void Player::setCalled(bool b){
  called = b;
}

void Player::resetCF(){
  called = false;
  folded = false;
}

int Player::getMoney(){
  return money;
}
void Player::setMoney(int _money){
  money = _money;
}

int Player::Play(int maxBet){
   char option = ' ';
   int raise = 0;
   std::cout << "(C/R/F)\n";
   std::cin >> option;
   while(!getCalled()){
   switch(option){
     case 'c':
     case 'C':
          called = true;
          money -= maxBet;
          return maxBet;
     case 'r':
     case 'R':
          std::cout << "How much you would you like to raise by: ";
          std::cin >> raise;
          money -= maxBet + raise;
          called = true;
          return maxBet+raise;
     case 'f':
     case 'F':
        folded = true;
        return maxBet;


   }
 }
}
