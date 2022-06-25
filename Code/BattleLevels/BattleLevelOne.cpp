#include "../GameHandler.h"
using namespace std::chrono_literals;

void levelOneInstructions(std :: string name)
{
  system("clear");
  std :: cout << " Great work " + name + ", " << std :: endl << std :: endl;
  std :: cout << " You Have Now Reached To 'Thunder Lord', The Mist Valley!" << std :: endl; 
  std :: cout << " Here you can get the 'Map' for your further journey."  << std :: endl;
  std :: cout << " But wait, to get that map you have to defeat the enemy who is guarding that map." << std :: endl << std :: endl << std :: endl;
}

void showStats(Player* player, Enemy* enemy)
{
  if(player -> getPlayerHealth() < 0) 
  {
    player -> setPlayerHealth(0);
  }
  std::cout << std::endl;
  std :: cout << player -> getPlayerName() << "'s " << "Health : " << player -> getPlayerHealth() << std :: endl;
  
  getEnemyStats(enemy);
  std::cout << std::endl;
}

void startLevelOne(std::string name)
{
  levelOneInstructions(name);
  moveForward();
  //system("clear");
  std::cout << " bingooo! You found the Map, but you have to defeat the enemies to get that map." << std::endl << std::endl;
  
  while(true)
  {
    std::cout << "Press 'B' to battle with enemy... " ;
    std::string input;
    std::cin >> input;
    if(!(input == "B" || input == "b"))
    {
      std::cout << " Hey Player, it's time to show your Bravery!" << std::endl << std::endl;
    }
    else {
      break;
    }
  }
}

void attack(Player* player, Enemy* enemy)
{
  //system("clear");
  std::cout << "Attack : "  << std::endl;
  player -> randomRangedDamage();
  enemy -> randomEnemyDamage();

  std::cout << "Additional Damage by Player : "<< player -> getMeleeDamage() << " + " <<player -> getRangedDamage() << std::endl;

  enemy -> setEnemyHealth(enemy -> getEnemyHealth() - (player -> getMeleeDamage() + player -> getRangedDamage()));

  std::cout << "Total damage given by Player : " << player -> getMeleeDamage() + player -> getRangedDamage() << std::endl ;

  player -> setPlayerHealth(player -> getPlayerHealth() - enemy -> getEnemyDamage());

  std::cout << "Total damage given by Enemy : " << enemy -> getEnemyDamage() << std::endl;

  showStats(player, enemy);
}

void defence(Player* player, Enemy* enemy)
{
  //system("clear");
  std::cout << std::endl << "After using defence :- "  << std::endl;
  showStats(player, enemy);
  
}

void levelOneBattle(Player* player)
{
  Enemy* enemy = new Enemy("1st Enemy", normalEnemyType, 30, 5);
  std :: string input; 
  //system("clear");
  std::cout << "Get Ready Player!" << std::endl;
  showStats(player, enemy);
  
  srand(time(0));
  while(true)
  {
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);

      if(enemy -> getEnemyHealth() <= 0) 
      {
        break; 
      }
      
      switch(rand() % 3)
      {
        case 0:
          attack(player, enemy);
          break;
        case 1:
          defence(player, enemy);
          break;
        default:
          attack(player, enemy);
          break;
      }
    
  }

  std::cout << std::endl << std::endl << " !! Cheers, You Won The Battle !!" << std::endl << std::endl; 
  std::cout << " Press Enter To Continue... ";
  std::cin.get();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

  //system("clear");
  std::cout << " Well done " + player->getPlayerName() + "," << std::endl << std::endl;
  std::cout << " You have recaptured Thunder Lord. Now you have the map for the further journey." << std::endl;
  std::cout << " One down, five more to go. Good luck Player!" << std::endl<< std::endl; 
  moveForward();
  
  delete enemy;
}