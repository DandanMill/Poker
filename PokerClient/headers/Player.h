#ifndef PLAYER
#define PLAYER

class Player{
public:
  Player(int _id,bool _called);
  Player(int _id);
  int getMoney();
  void setMoney(int _money);
  bool getCalled();
  void setCalled(bool b);
  int getId();
  bool getFolded();
  void resetCF();
  void checkBet(int maxBet);
  int getBet();
  void setBet(int _bet);
  int Play(int maxBet);
private:
  int id;
  int money;
  bool called;
  int bet;
  bool folded;
};

#endif
