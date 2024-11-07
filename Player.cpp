#include "Player.h"

Player::Player() {}

int Player::get_damage()
{
    return damage;
}
int Player::get_points()
{
    return points;
}
void Player::take_points(int enemy_points)
{
    points += enemy_points;
}

//int Player::get_count_enemy()
//{
//    return count_enemy;
//}