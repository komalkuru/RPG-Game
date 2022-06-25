#include <string>

enum SpecialAbility {
  criticalHit,
  rangedAttack
  //blocker
};

enum MeleeDamage {
  sword,
  shield,
  armour,
  bow
};

class Player {
  int playerHealth;
  int meleeDamage;
  int rangedDamage;
  int defence;
  int playerLevel;
  std :: string playerName;
  std :: string playerVillage;
  SpecialAbility specialAbility;

  public:
    Player(std :: string, std :: string, int, int);

    std :: string const getPlayerName();
    void setPlayerName(std :: string);

    std :: string const getPlayerVillage();
    void setPlayerVillage(std :: string);

    int const getPlayerLevel();
    void setPlayerLevel(int);

    int const getPlayerHealth();
    void setPlayerHealth(int);

    int const getMeleeDamage();
    void setMeleeDamage(int);

    int const getRangedDamage();
    void setRangedDamage(int);

    int const getDefence();
    void setDefence(int);
    SpecialAbility const getSpecialAbility();
    void setSpecialAbility(SpecialAbility);

    void randomRangedDamage();
};