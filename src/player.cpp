#include "player.hpp"
#include "settings.hpp"
#include <iostream>

Player::Player() {}

void Player::update()
{
    float dt = GetFrameTime();

    Vector2 mousePos = GetMousePosition();
    Vector2 distance = Vector2Subtract(pos, mousePos);

    rotation = (atan(distance.x / distance.y) * 180 / PI);
}

void Player::render()
{
    DrawRectanglePro(playerRect, {20,20}, -rotation, RED);
}