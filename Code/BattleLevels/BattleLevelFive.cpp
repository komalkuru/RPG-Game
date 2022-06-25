#include "../GameHandler.h"

using namespace std::chrono_literals;

void levelFiveInstructions(std::string name)
{
  system("clear");
  std::cout << "Great work " + name + "," << std::endl << std::endl;
  std::cout << "You Have Now Reached To 'Bow Land', The Valley Of bows!" << std::endl;
  std::cout << "Here you can get the 'Bow' you needed to defeat Murlocs."  << std::endl;
  std::cout << "But to get that bow you have to defeat the enemies who are guarding that bow." << std::endl << std::endl << std::endl;
}

void showStats(Player* player, Enemy* enemy1, Enemy* enemy2, Enemy* enemy3, Enemy* enemy4, Enemy* enemy5)
{
  if(player -> getPlayerHealth() < 0) 
  {
    player -> setPlayerHealth(0);
  }
  std::cout << std::endl;
  std::cout << player -> getPlayerName() << "'s " << " Health : " << player -> getPlayerHealth() << std::endl;

  getEnemyStats(enemy1);
  getEnemyStats(enemy2);
  getEnemyStats(enemy3);
  getEnemyStats(enemy4);
  getEnemyStats(enemy5);

  std::cout << std::endl;
}

void startLevelFive(std::string name)
{
  levelFiveInstructions(name);
  moveForward();

  //system("clear");
  std::cout << std::endl << "Bingooo! You found the bow, but you have to defeat those monsters to get that bow." << std::endl << std::endl;
  
  while(true)
  {
    std::cout << "Press 'B' to battle with enemy... " ;
    std::string input;
    std::cin >> input;
    if(!(input == "B" || input == "b"))
    {
      std::cout << "Hey Warrior, it's time to show your Bravery!" << std::endl << std::endl;
    }
    else break;
  }
}

void attack(Player* player, Enemy* enemy1, Enemy* enemy2, Enemy* enemy3, Enemy* enemy4, Enemy* enemy5)
{
  bool specialAbilityUsed = false;

  //system("clear");
  std::cout << "Attack :- " << std::endl;

  srand(time(0));
  switch(rand() % 1)
  {
    case 0:
      player -> setMeleeDamage ( player -> getMeleeDamage() * 2 );
      std::cout << "Special Ability Used : Critical Hit" << std::endl;

      std::cout << "After using special ability by Player : "<< player -> getMeleeDamage() << std::endl;
      
      specialAbilityUsed = true;
      break;

    default:
      player -> randomRangedDamage();
      break;
  }
  player -> randomRangedDamage();
  checkIsAlive(enemy1);
  checkIsAlive(enemy2);
  checkIsAlive(enemy3);
  checkIsAlive(enemy4);
  checkIsAlive(enemy5);
  
  srand(time(0));
  std::this_thread::sleep_for(1s);
  
  switch( rand() % 5 )
  {
    case 0:
      if( ( enemy1 -> getEnemyHealth() <= 0 ) ) {}
      else
      {
        std::cout << "Additional Damage by Player : "<< player -> getMeleeDamage() << " + " <<player -> getRangedDamage() << std::endl;

        enemy1 -> setEnemyHealth (enemy1 -> getEnemyHealth() - (player -> getMeleeDamage() + player -> getRangedDamage()));

        std::cout << "Total damage given by Player : " << player -> getMeleeDamage() + player -> getRangedDamage() << std::endl;
        break;
      }
      
    case 1:
      if((enemy2 -> getEnemyHealth() <= 0)) {}
      else
      {
        std::cout << "Additional Damage by Player : "<< player -> getMeleeDamage() << " + " <<player -> getRangedDamage() << std::endl;

        enemy2 -> setEnemyHealth (enemy2 -> getEnemyHealth() - (player -> getMeleeDamage() + player -> getRangedDamage()));

        std::cout << "Total damage given by Player : " << player -> getMeleeDamage() + player -> getRangedDamage() << std::endl;
        break;
      }

    case 2:
      if((enemy3 -> getEnemyHealth() <= 0)) {}
      else
      {
        std::cout << "Additional Damage by Player : "<< player -> getMeleeDamage() << " + " <<player -> getRangedDamage() << std::endl;

        enemy3 -> setEnemyHealth (enemy3 -> getEnemyHealth() - (player -> getMeleeDamage() + player -> getRangedDamage()));

        std::cout << "Total damage given by Player : " << player -> getMeleeDamage() + player -> getRangedDamage() << std::endl;
        break;
      }

    case 3:
      if( ( enemy4 -> getEnemyHealth() <= 0 ) ) {}
      else
      {
        std::cout << "Additional Damage by Player : "<< player -> getMeleeDamage() << " + " <<player -> getRangedDamage() << std::endl;

        enemy4 -> setEnemyHealth (enemy4 -> getEnemyHealth() - (player -> getMeleeDamage() + player -> getRangedDamage()));

        std::cout << "Total damage given by Player : " << player -> getMeleeDamage() + player -> getRangedDamage() << std::endl;
        break;
      }

    case 4:
      if( ( enemy5 -> getEnemyHealth() <= 0 ) ) {}
      else
      {
        std::cout << "Additional Damage by Player : "<< player -> getMeleeDamage() << " + " <<player -> getRangedDamage() << std::endl;
        
        enemy5 -> setEnemyHealth (enemy5 -> getEnemyHealth() - (player -> getMeleeDamage() + player -> getRangedDamage()));

        std::cout << "Total damage given by Player : " << player -> getMeleeDamage() + player -> getRangedDamage() << std::endl;
        break;
      }

    default:
      std::cout << "Additional Damage by Player : "<< player -> getMeleeDamage() << " + " <<player -> getRangedDamage() << std::endl;
      
      enemy1 -> setEnemyHealth (enemy1 -> getEnemyHealth() - (player -> getMeleeDamage() + player -> getRangedDamage()));

      std::cout << "Total damage given by Player : " << player -> getMeleeDamage() + player -> getRangedDamage() << std::endl;
      break;
  }

  player -> setPlayerHealth ( player -> getPlayerHealth() - (enemy1 -> getEnemyDamage() + enemy2 -> getEnemyDamage() + enemy3 -> getEnemyDamage() +  enemy4 -> getEnemyDamage() + enemy5 -> getEnemyDamage()));

  std::cout << "Total damage given by Enemy : " << (enemy1 -> getEnemyDamage() + enemy2 -> getEnemyDamage() + enemy3 -> getEnemyDamage() +  enemy4 -> getEnemyDamage() + enemy5 -> getEnemyDamage()) << std::endl << std :: endl;

  showStats( player, enemy1, enemy2, enemy3, enemy4, enemy5 );
  std::cout << std::endl;

  if(specialAbilityUsed)
  {
    player -> setMeleeDamage ( player -> getMeleeDamage() / 2 );
    specialAbilityUsed = false;
  }
}

void defence( Player* player, Enemy* enemy1, Enemy* enemy2, Enemy* enemy3, Enemy* enemy4, Enemy* enemy5 )
{
  //system("clear");
  std::cout << std::endl << "After using Defence : - " << std::endl;
  showStats( player, enemy1, enemy2, enemy3, enemy4, enemy5 );
}

void levelFiveBattle( Player* player )
{
  Enemy* enemy1 = new Enemy("1st Enemy", normalEnemyType, 30, 5);
  Enemy* enemy2 = new Enemy("2nd Enemy", normalEnemyType, 30, 5);
  Enemy* enemy3 = new Enemy("3rd Enemy", normalEnemyType, 30, 5);
  Enemy* enemy4 = new Enemy("4th Enemy", normalEnemyType, 30, 5);
  Enemy* enemy5 = new Enemy("5th Enemy", normalEnemyType, 30, 5);

  std::string input; 
  //system("clear");
  std::cout << "Get Ready Player!" << std::endl;
  showStats(player, enemy1, enemy2, enemy3, enemy4, enemy5);
  
  while(true)
  {
    if(enemy1 -> getEnemyHealth() <= 0 && enemy2 -> getEnemyHealth() <= 0 && enemy3 -> getEnemyHealth() <= 0 && enemy4 -> getEnemyHealth() <= 0 && enemy5 -> getEnemyHealth() <= 0) break; 
    if(player -> getPlayerHealth() <= 0) 
    {
      std::cout << std::endl << std::endl << "Opps! You Lost The Battle!" << std::endl;
      std::cout << "Try Again!" << std::endl; 
      exit(1);
    }

    srand(time(0));
    std::this_thread::sleep_for(1s);
    
    switch(rand() % 3)
    {
      case 0:
        attack(player, enemy1, enemy2, enemy3, enemy4, enemy5);
        break;
      case 1:
        defence(player, enemy1, enemy2, enemy3, enemy4, enemy5);
        break;
      default:
        attack(player, enemy1, enemy2, enemy3, enemy4, enemy5);
        break;
    }
  }

  std::cout << std::endl << std::endl << "!! Hurrah, You Won The Battle !!" << std::endl << std::endl;
  std::cout << "Press Enter To Continue... ";
  std::cin.get();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

  //system("clear");
  std::cout << std::endl << "Well done " + player -> getPlayerName() + "," << std::endl << std::endl;
  std::cout << "You have recaptured Bow Land. Now you have the bow to defeat Murlocs." << std::endl;
  std::cout << "Also a special ability is unlocked - Ranged Attack (After performing this attack, you won't take damage for the next attack of the enemy)." << std::endl;
  std::cout << "Five down, the last one to go. Good luck warrior!" << std::endl<< std::endl;
  moveForward();
  
  delete enemy1;
  delete enemy2;
  delete enemy3;
  delete enemy4;
  delete enemy5;
}