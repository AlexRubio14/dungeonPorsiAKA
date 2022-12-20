#include "Enemy.h"

void Enemy::Init() {

    position.x = RandomNumber(0, 4);
    position.y = RandomNumber(0, 4);

    maxHealth = RandomNumber(60, 90);
    health = maxHealth;

    maxStamina = RandomNumber(60, 90);
    stamina = maxStamina;

    isAlive = true;
}
