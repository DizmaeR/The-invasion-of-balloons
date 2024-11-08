#include "Player.h"

Player::Player() 
{
      //Отрисовка hp 
                                    //Добавить спрайт сердца
}

int Player::get_damage() const
{
    return damage;
}
int Player::get_points() const
{
    return points;
}
void Player::take_points(int enemy_points)
{
    points += enemy_points;
}
void Player::missed_click()
{
    health--;
}
int Player::get_health() const
{
    return health;
}

void Player::take_health(int savedHp)
{
    points += savedHp;
}