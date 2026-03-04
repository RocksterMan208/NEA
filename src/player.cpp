#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include <vector>

#include "player.hpp"
#include "settings.hpp"

Player::Player()
{
    Image playerIcon = LoadImage(playerIconPath.c_str());
    playerIconT = LoadTextureFromImage(playerIcon);
    UnloadImage(playerIcon);
}

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

    direction = Vector2Normalize(direction);

    if (direction.x == 0) velocity.x *= playerFriction;
    if (direction.y == 0) velocity.y *= playerFriction;

    velocity += direction * playerAccel * dt;

    velocity.x = Clamp(velocity.x, -playerMaxSpeed, playerMaxSpeed);
    velocity.y = Clamp(velocity.y, -playerMaxSpeed, playerMaxSpeed);

    pos += velocity * dt;

    if (IsKeyPressed(KEY_T)) health -= 10;
}

void Player::render()
{   
    Rectangle playerRect = {pos.x, pos.y, 40,40};
    
    DrawTexturePro
    (
        playerIconT,
        {0,0, (float)playerIconT.width, (float)playerIconT.height},
        (Rectangle)playerRect,
        {20,20},
        rotation+90, // Offset by 90 degrees to ensure correct rotation of the texture.
        RED
    );

    DrawRectangleV({pos.x-20, pos.y+30}, {40, 5}, RED);
    DrawRectangleV({pos.x-20, pos.y+30}, {(health*(40.0f/100.0f)), 5}, GREEN);

    DrawTextEx(defaultFont, "Bullets: Infinite", {0,0}, 24, 1, BLACK);
}