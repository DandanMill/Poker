#ifndef PLAYER
#define PLAYER

class Player{
public:
  Player(int _id);
  int getMoney();
  void setMoney(int _money);
  bool getCalled();
  void setCalled(bool b);
  int getId();
  void resetCF();
  int Play(int maxBet);
private:
  int id;
  int money;
  bool called;
  bool folded;
};

#endif
