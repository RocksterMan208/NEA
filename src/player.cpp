#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include <vector>

#include "player.hpp"
#include "settings.hpp"

Player::Player() {}

void Player::update()
{
    float dt = GetFrameTime();
    
    Vector2 mousePos = GetMousePosition();
    Vector2 distance = Vector2Subtract(mousePos, {pos.x, pos.y});

    rotation = (atan2(distance.y,distance.x)*RAD2DEG);

    direction.x = 0;
    direction.y = 0;

    if (IsKeyDown(KEY_W)) direction.y -= 1;
    if (IsKeyDown(KEY_S)) direction.y += 1;
    if (IsKeyDown(KEY_A)) direction.x -= 1;
    if (IsKeyDown(KEY_D)) direction.x += 1;

    pos.x += direction.x * playerAccel * dt;
    pos.y += direction.y * playerAccel * dt;
}

void Player::render()
{
    Rectangle playerRect = {pos.x, pos.y, 40,40};
    DrawRectanglePro(playerRect, {playerRect.width/2, playerRect.height/2}, rotation, RED);
}