#include "../GameHandler.h"
using namespace std::chrono_literals;

void levelSixInstructions(std::string name)
{
  system("clear");
  std::cout << "Great work " + name + "," << std::endl << std::endl; 
  std::cout << "You Have Now Reached To 'Wonder Land', The Land of crystels!" << std::endl << std::endl;
  std::cout << "This is the last territory captured by Murlocs. To recapture this you have to defeat Murlocs."  << std::endl << std::endl;
  std::cout << "But be carefull, Murlocs is not like the rest of the enemies. He has different powers." << std::endl << std::endl;
  std::cout << "Remeber, you have to use sword, shield, armour and bow that you have collected so far, to defeat the Murlocs." << std::endl << std:: endl;
  std::cout << "Good luck warrior!" << std::endl << std::endl;
}

void showStats(Enemy* enemy, Player* player)
{
  if( player -> getPlayerHealth() < 0 ) 
  {
    player -> setPlayerHealth(0);
  }
  std::cout << std::endl;
  std::cout << std::endl << player -> getPlayerName() << "'s " << " Health : " << player -> getPlayerHealth() << std::endl;

  getEnemyStats(enemy);
  std::cout << std::endl;
}

void startLevelSix(std::string name)
{
  levelSixInstructions(name);
  moveForward();

  //system("clear");
  std::cout << std::endl << "Bingooo! You found the Murlocs. Let's take back what is our's" << std::endl << std::endl;
  
  while(true)
  {
    std::cout << "Press 'B' to battle with Murlocs... " ;
    std::string input;
    std::cin >> input;
    if(!(input == "B" || input == "b"))
    {
      std::cout << "Hey Player, it's time to show your Bravery!" << std::endl << std::endl;
    }
    else break;
  }
}

void attack(Enemy* enemy, Player* player)
{
  bool specialAbilityUsed = false;
  bool specialAbilityMurlocs = false;

  //system("clear");
  std::cout << std::endl << "Attack :" << std::endl;

  srand(time(0));
  std::this_thread::sleep_for(1s);

  if(rand() % 5 == 0)
  {
    player -> setMeleeDamage ( player -> getMeleeDamage() * 2 );
    std::cout << "Special Ability Used : Critical Hit" << std::endl;
    specialAbilityUsed = true;
  }
  else
  {
    player -> randomRangedDamage();
  }

  checkIsAlive(enemy);

  if(rand() % 5 == 0)
  {
    enemy->setEnemyDamage(0);
    std::cout << "Special Ability Used : Blocker" << std::endl;
  }

  if(rand() % 5 == 0)
  {
    player->setPlayerHealth(player->getPlayerHealth() + 15);
    std::cout << "Special Ability Used by player : Life Steal" << std::endl;
    std::cout << "After using special ability by Player : "<< player -> getPlayerHealth() << std::endl;
  }
  
  player -> randomRangedDamage();
  std::cout << "Additional Damage given by Player : "<< player -> getMeleeDamage() << " + " <<player -> getRangedDamage() << std::endl;

  enemy->setEnemyHealth(enemy->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));
  
  std::cout << "Total damage given by Player : " << player -> getMeleeDamage() + player -> getRangedDamage() << std::endl;

  if(rand() % 7 == 0)
  {
    std::cout << "Special Ability Used By Murlocs : Ground Slash" << std::endl;
    enemy->setEnemyDamage(enemy->getEnemyDamage() * 2);
    std::cout << "After using special ability by Murlocs : "<< enemy -> getEnemyDamage() << std::endl;
  }

  if(rand() % 7 == 0)
  {
    std::cout << "Special Ability Used By Murlocs : Health Regeneration" << std::endl;
    enemy->setEnemyHealth(enemy->getEnemyHealth() + 10);
    std::cout << "After using special ability by Murlocs : "<< enemy -> getEnemyHealth() << std::endl;
  }
  
  player -> setPlayerHealth(player -> getPlayerHealth() - (enemy -> getEnemyDamage()));

  std::cout << "Total damage given by Murlocs : " << enemy -> getEnemyDamage() << std::endl; 

  showStats(enemy, player);

  if(specialAbilityUsed)
  {
    player -> setMeleeDamage(player -> getMeleeDamage() / 1.5);
    specialAbilityUsed = false;
  }

  // std::cout << enemy->getEnemyName() << " Damage Given by player :- " << enemy->getEnemyDamage() << std::endl;
  
  if(specialAbilityMurlocs)
  {
    enemy->setEnemyDamage(enemy -> getEnemyDamage() / 1.5);
    specialAbilityMurlocs = false;
  }
}

void defence(Enemy* enemy, Player* player)
{
  //system("clear");
  std::cout << "After using defence :- " << std::endl;
  showStats(enemy, player);
}

void levelSixBattle(Player* player)
{
  Enemy* enemy = new Enemy("Murlocs", bossEnemyType, 100, 10);

  std::string input; 
  //system("clear");
  std::cout << "Get Ready Warrior!" << std::endl;
  showStats(enemy, player);
  
  while(true)
  {
    if(enemy->getEnemyHealth() <= 0) break; 
    if(player->getPlayerHealth() <= 0) 
    {
      std::cout << std::endl << std::endl << "Opps! You Lost The Battle!" << std::endl;
      std::cout << "Try Again!" << std::endl; 
      exit(1);
    }

    srand(time(0));
    std::this_thread::sleep_for(1s);

    switch(rand() % 2)
    {
      case 0:
        attack(enemy, player);
        break;
      case 1:
        defence(enemy, player);
        break;
      default:
        attack(enemy, player);
        break;
    }
  }

  std::cout << std::endl << std::endl << "!! Hurrah, You Won The Battle !!" << std::endl;
  std::cout << std::endl << "Press Enter To Continue... ";
  std::cin.get();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

  //system("clear");
  std::cout << "Congratulations Player " + player -> getPlayerName() + "," << std::endl << std::endl;
  std::cout << "You have defeated Murlocs and recaptured Wonder Land." << std::endl;
  std::cout << "The lands of crystels has seen your bravery and will alwayas be remembered." << std::endl;
  std::cout << "Player " + player -> getPlayerName() + "!" << std::endl<< std::endl;
  
  std::cout << "Press Enter To Exit... ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  delete enemy;
}