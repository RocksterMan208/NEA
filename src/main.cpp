#include <iostream>
#include "raylib.h"

#include "settings.hpp"

#include "player.hpp"

int main()
{
InitWindow(screenWidth,screenHeight,"Shooter");
SetTargetFPS(fps);

Player player;

while (!WindowShouldClose())
{
    player.update();
    
    BeginDrawing();
    ClearBackground(RAYWHITE);

    player.render();

    EndDrawing();
}

return -1;
}