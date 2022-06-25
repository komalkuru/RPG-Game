#include "GameHandler.h"
#include "BattleLevels/BattleLevelOne.h"
#include "BattleLevels/BattleLevelTwo.h"
#include "BattleLevels/BattleLevelThree.h"
#include "BattleLevels/BattleLevelFour.h"
#include "BattleLevels/BattleLevelFive.h"
#include "BattleLevels/BattleLevelSix.h"

void getEnemyStats(Enemy* enemy)
{
  if(enemy -> getEnemyHealth() < 0) 
  {
    enemy -> setEnemyHealth(0);
  }
  
  if(enemy -> getEnemyHealth() > 0 ) {
    std :: cout << enemy -> getEnemyName() + "'s" << " Health : " << enemy -> getEnemyHealth() << std::endl;  
  }
}

void checkIsAlive(Enemy* enemy)
{
  if(!(enemy->getEnemyHealth() <= 0 ))
  {
    enemy -> randomEnemyDamage();
  }
  else
  {
    enemy -> setEnemyDamage(0);
  }
}

void moveForward()
{
  while(true)
  {
    std :: cout << "Press 'F' to move forward...  ";
    std :: string input;
    std :: cin >> input;
    if(!(input == "F" || input == "f" ))
    {
      std :: cout << "Opps! You are hitting in wrong direction" << std :: endl << std :: endl;
    }
    else break;
  }
}

std :: string playerCredentials()
{
  char name[50];
  std :: cout << "Enter your name : ";
  std :: cin >> name;
  return (std :: string)name;
}

void instructions(std::string name)
{
  //system("clear");
  std :: cout << "Hi " << name + "," << std :: endl << std :: endl;
  std :: cout << "Welcome To 'Wonder Land', The Land Of The Crystel!" << std :: endl << std::endl;
  std :: cout << "Our land is captured by a monster named 'Murlocs' :( and we need your help to get back our land." << std :: endl << std::endl;
  std :: cout << "To reach their you have to cross 5 enemies of Lands which are full of enemies." << std :: endl << std::endl;
  std :: cout << "You will need sword, shield, armour and bow to defeat Murlocs." << std :: endl << std :: endl;
  std :: cout << "Best luck to the finest player we have ever known!" << std :: endl << std :: endl<< std :: endl;

  std::cout << "Press Enter To Begin The Journey... ";
  std::cin.get();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}


void gameStart()
{
  std :: string name = playerCredentials();
  instructions(name);

  Player* player = new Player(name, "Land", 500, 20);

  startLevelOne(name);
  levelOneBattle(player);
  
  startLevelTwo(name);
  levelTwoBattle(player);

  startLevelThree(name);
  levelThreeBattle(player);

  startLevelFour(name);
  levelFourBattle(player);

  startLevelFive(name);
  levelFiveBattle(player);

  startLevelSix(name);
  levelSixBattle(player);

  delete player;
}