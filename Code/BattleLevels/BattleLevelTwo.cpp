#include "../GameHandler.h"

using namespace std::chrono_literals;

void levelTwoInstructions(std :: string name)
{
  system("clear");
  std::cout << "Great work " + name + "," << std::endl << std::endl;
  std::cout << "You Have Now Reached To 'Sword Land', The field of Swords!" << std::endl;
  std::cout << "Here you can get the 'Sword' you needed to defeat Murlocs."  << std::endl;
  std::cout << "But to get that sword you have to defeat the enemies who are guarding that sword." << std::endl << std::endl << std::endl;
}

void showStats(Player* player, Enemy* enemy1, Enemy* enemy2)
{
  if(player -> getPlayerHealth() < 0) 
  {
    player -> setPlayerHealth(0);
  }
  std::cout << std::endl;
  std::cout << player -> getPlayerName() << "'s " << "Health : " << player -> getPlayerHealth() << std::endl;

  getEnemyStats(enemy1);
  getEnemyStats(enemy2);
  std::cout << std::endl;
}

void startLevelTwo(std::string name)
{
  levelTwoInstructions(name);
  moveForward();

  std::cout << "Bingooo! You found the Sword, but you have to defeat those monsters to get that sword." << std::endl << std::endl; 
  
  while(true)
  {
    std::cout << "Press 'B' to battle with enemies... " ;
    std::string input;
    std::cin >> input;
    if(!(input == "B" || input == "b"))
    {
      std::cout << "Hey Player, it's time to show your Bravery!" << std::endl << std::endl;
    }
    else break;
  }
}

void attack(Player* player, Enemy* enemy1, Enemy* enemy2)
{
  std::cout << std::endl << "Attack :" << std::endl;
  player->randomRangedDamage();
  checkIsAlive(enemy1);
  checkIsAlive(enemy2); 

  srand(time(0));
  switch(rand() % 2)
  {
    std::this_thread::sleep_for(1s);
    case 0:
      if((enemy1 -> getEnemyHealth() <= 0 )) {}
      else
      {
        std::cout << "Additional Damage by Player : "<< player -> getMeleeDamage() << " + " <<player -> getRangedDamage() << std::endl;

        enemy1 -> setEnemyHealth(enemy1 -> getEnemyHealth() - (player -> getMeleeDamage() + player -> getRangedDamage()));
        
        std::cout << "Total damage given by Player : " << player -> getMeleeDamage() + player -> getRangedDamage() << std::endl ;

        break;
      }
      
    case 1:
    {
      std::cout << "Additional Damage by Player : "<< player -> getMeleeDamage() << " + " <<player -> getRangedDamage() << std::endl;

      enemy2 -> setEnemyHealth(enemy2 -> getEnemyHealth() - (player -> getMeleeDamage() + player -> getRangedDamage()));

      std::cout << "Total damage given by Player : " << player -> getMeleeDamage() + player -> getRangedDamage() << std::endl ;

      break;
    }
  }
  player -> setPlayerHealth(player -> getPlayerHealth() - (enemy1 -> getEnemyDamage() + enemy2 -> getEnemyDamage()));

  std::cout << "Total damage given by Enemy : " << (enemy1 -> getEnemyDamage() + enemy2 -> getEnemyDamage()) << std::endl;

  showStats(player, enemy1, enemy2);
}

void defence(Player* player, Enemy* enemy1, Enemy* enemy2)
{
  std::cout << "After using defence :- " << std::endl;
  showStats(player, enemy1, enemy2);
}

void levelTwoBattle(Player* player)
{
  Enemy* enemy1 = new Enemy("1st Enemy", normalEnemyType, 30, 5);
  Enemy* enemy2 = new Enemy("2nd Enemy", normalEnemyType, 30, 5);

  std::string input; 
  //system("clear");
  std::cout << "Get Ready Player!" << std::endl;
  showStats(player, enemy1, enemy2);
  
  srand(time(0));
  while(true)
  {
    if(enemy1 -> getEnemyHealth() <= 0 && enemy2 -> getEnemyHealth() <= 0) {
      break;
    }  
    
    if(player -> getPlayerHealth() <= 0) 
    {
      std::cout << std::endl << std::endl << "Opps! You Lost The Battle!" << std::endl;
      std::cout << "Try Again!" << std::endl << std::endl; 
      exit(1);
    }

    std::this_thread::sleep_for(1s);
    
    switch(rand() % 3)
    {
      case 0:
        attack(player, enemy1, enemy2);
        break;
      case 1:
        defence(player, enemy1, enemy2);
        break;
      default:
        attack(player, enemy1, enemy2);
        break;
    }
  }

  std::cout << std::endl << std::endl << "!! Cheers, You Won The Battle !!" << std::endl << std::endl;
  std::cout << "Press Enter To Continue... ";
  std::cin.get();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

  //system("clear");
  std::cout << "Well done " + player -> getPlayerName() + "," << std::endl << std::endl; 
  std::cout << "You have recaptured Sword Land. Now you have the sword to defeat Murlocs." << std::endl; 
  std::cout << "Also a special ability is unlocked - Critical hit.(performs attack with massive damage)." << std::endl; 
  std::cout << "Two down, four more to go. Good luck player!" << std::endl << std::endl; 
  moveForward();
  
  delete enemy1;
  delete enemy2;
}
