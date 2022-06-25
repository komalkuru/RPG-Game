#include "Enemy.h"

Enemy :: Enemy(std :: string name, EnemyType type, int health, int damage) {
  setEnemyName(name);
  setEnemyType(type);
  setEnemyDamage(damage);
  setEnemyHealth(health);
}

std :: string const Enemy :: getEnemyName() {
  return enemyName;
}

void Enemy :: setEnemyName(std :: string name) {
  enemyName = name;
}

EnemyType const Enemy :: getEnemyType() {
  return enemyType;
}

void Enemy :: setEnemyType(EnemyType type) {
  enemyType = type;
}

int const Enemy :: getEnemyDamage() {
  return enemyDamage;
}

void Enemy :: setEnemyDamage(int damage) {
  enemyDamage = damage;
}

int const Enemy :: getEnemyHealth() {
  return enemyHealth;
}

void Enemy :: setEnemyHealth(int health) {
  enemyHealth = health;
}

void Enemy::randomEnemyDamage()
{
  srand(time(0));
  if(enemyType == bossEnemyType)
  {
    int minDamage = 10;
    int maxDamage = 20;

    srand(time(0));
    setEnemyDamage( rand() % ( maxDamage - minDamage + 1 ) + minDamage );
  }
  else
  {
    int minDamage = 5;
    int maxDamage = 10;

    srand(time(0));
    setEnemyDamage( rand() % ( maxDamage - minDamage + 1 ) + minDamage ); 
  }
}