#include "Player.h"
#include <iostream>

Player::Player(){
  money = 1000;
  called = false;
}

bool Player::getCalled(){
  return called;
}

void Player::setCalled(bool b){
  called = b;
}

int Player::getMoney(){
  return money;
}
int Player::setMoney(int _money){
  money = _money;
}

int Player::Play(int maxBet){
   char option = ' ';
   int raise = 0;
   std::cout << "(C/R/F)\n";
   std::cin >> option;
   while(!called){
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
        called = true;
        return maxBet;


   }
 }
}
