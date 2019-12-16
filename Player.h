#ifndef PLAYER
#define PLAYER

class Player{
public:
  Player();
  int getMoney();
  int setMoney(int _money);
  bool getCalled();
  void setCalled(bool b);
  int Play(int maxBet);
private:
  int money;
  bool called;
};

#endif
