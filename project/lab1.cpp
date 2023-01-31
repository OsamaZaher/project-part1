// user press 1 to attack and press 2 to speed off from the attack very basic code 
// part1 done by me :)
// name: Osama Zaher Mahmoud Hadrb 
// SID: 1211307648
// https://youtu.be/KPCSitoK7fA
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

const int HEALTH = 100;
const int ENEMY_HEALTH = 70;

class Player
{
  public:
    int health;
    bool speedPowerUp;

    Player()
    {
        health = HEALTH;
        speedPowerUp = false;
    }

    void takeDamage(int damage)
    {
        health -= damage;
    }

    void useSpeedPowerUp()
    {
        speedPowerUp = true;
    }
};

class Enemy
{
  public:
    int health;

    Enemy()
    {
        health = ENEMY_HEALTH;
    }

    void takeDamage(int damage)
    {
        health -= damage;
    }
};

void drawBoard(int playerHealth, int enemyHealth)
{
    std::cout << "Player health: " << playerHealth << std::endl;
    std::cout << "Enemy health: " << enemyHealth << std::endl;
}

int main()
{
    srand(time(NULL));

    Player player;
    Enemy enemy;

    while (player.health > 0 && enemy.health > 0)
    {
        drawBoard(player.health, enemy.health);

        int choice;
        std::cout << "1. Attack\n2. Use speed power-up\nChoice: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int damage = rand() % 10 + 1;
                std::cout << "Player dealt " << damage << " damage to the enemy." << std::endl;
                enemy.takeDamage(damage);
                break;
            }
            case 2:
            {
                if (!player.speedPowerUp)
                {
                    std::cout << "Player used speed power-up." << std::endl;
                    player.useSpeedPowerUp();
                }
                else
                {
                    std::cout << "Speed power-up already in use." << std::endl;
                }
                break;
            }
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }

        if (enemy.health > 0)
        {
            int damage = rand() % 10 + 1;
            std::cout << "Enemy dealt " << damage << " damage to the player." << std::endl;
            player.takeDamage(damage);
        }
    }

    if (player.health <= 0)
    {
        std::cout << "Player lost." << std::endl;
    }
    else
    {
        std::cout << "Player won." << std::endl;
    }

    return 0;
}
