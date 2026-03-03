#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include <vector>

#include "player.hpp"
#include "settings.hpp"

int main()
{
InitWindow(screenWidth,screenHeight,"Shooter");
SetTargetFPS(fps);

Player player;
std::vector<bullet> bullets;

while (!WindowShouldClose())
{
    float dt = GetFrameTime();

    player.update();

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        bullet b;
        b.rotation = -player.rotation;
        b.size = {10,10};
        
        b.pos = player.pos;

        b.speed.x = bulletSpeed * cos((DEG2RAD*player.rotation));
        b.speed.y = bulletSpeed * sin((DEG2RAD*player.rotation));

        bullets.push_back(b);
    }

    for (auto &bullet : bullets) bullet.pos += bullet.speed * dt;
    
    BeginDrawing();
    ClearBackground(RAYWHITE);
    
    for (auto &b : bullets) b.render();

    player.render();

    EndDrawing();
}

return 0;
}