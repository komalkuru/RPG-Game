#include <string>

enum EnemyType {
  normalEnemyType,
  bossEnemyType
};

enum AttackType {
  groundSlash,
  speedDash,
  healthGeneration
};

class Enemy {
  int enemyDamage;
  int enemyHealth;
  std :: string enemyName;
  EnemyType enemyType;
  AttackType attackType;  

  public:
    Enemy(std :: string, EnemyType, int, int);

    std :: string const getEnemyName();
    void setEnemyName(std :: string);

    int const getEnemyHealth();
    void setEnemyHealth(int);

    int const getEnemyDamage();
    void setEnemyDamage(int);

    AttackType const getAttackType();
    void setAttackType(AttackType);

    EnemyType const getEnemyType();
    void setEnemyType(EnemyType);

    void randomEnemyDamage();
};
