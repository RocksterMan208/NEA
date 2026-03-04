// Here I include all system structures and essentials, I include raylib here as it is what I am using to code the game.
#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include <vector>

// Here I included all my self-made header files which include settings and essential functions for the game.
#include "player.hpp"
#include "settings.hpp"

//---------------------------------------------------------------------------------------------------------------------

int main()
{

//Initialising the window to allow for rendering.
InitWindow(screenWidth,screenHeight,"Shooter");

// Obtaining the monitor number as int then setting the target fps to be the refresh rate of the monitor.
int monitor = GetCurrentMonitor();
float fps = GetMonitorRefreshRate(monitor);

SetTargetFPS(fps);
HideCursor();

// Using self-made object and creating a vector using a struct function I made in player.hpp
Player player;
std::vector<bullet> bullets;

// Crosshair loading as a texture. (Crosshair path stated in settings.hpp)
Image crosshair = LoadImage(crosshairIconPath.c_str());
ImageResize(&crosshair, 32,32);
Texture2D crosshairT = LoadTextureFromImage(crosshair);
UnloadImage(crosshair);

// Starting the frame loop of the program
while (!WindowShouldClose())
{
    // Obtaining the frame time to allow for accurate movement calculations when on differing frame rates.
    float dt = GetFrameTime();

    // This function updates all the functions of the player and all code can be found for this inside of the player.cpp file
    player.update();

    // Processes thye firing input for the bullets and the player
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) | IsKeyPressed(KEY_SPACE))
    {
        bullet b;
        b.rotation = -player.rotation;
        
        // Ensuring that the bullet will ALWAYS be fired from the players current position.
        b.pos = player.pos;

        // Using trigonometry to calculate the correct speeds for each axis for the bullet to reach a specified location
        b.speed.x = bulletSpeed * cos((DEG2RAD*player.rotation));
        b.speed.y = bulletSpeed * sin((DEG2RAD*player.rotation));

        // Simply adds the bullet to the vector
        bullets.push_back(b);
    }

    for (auto &bullet : bullets)
    {
        bullet.pos += bullet.speed * dt;
        if (bullet.pos.x > GetScreenWidth()+50 || bullet.pos.y > GetScreenHeight()+50 || bullet.pos.x < -50 || bullet.pos.y < -50)
        {
            bullets.erase(bullets.begin());
        }
    }
    
    // Initiating the rendering loop
    BeginDrawing();
    ClearBackground(RAYWHITE);
    
    for (auto &b : bullets) b.render();
    player.render();


    // Drawing the crosshair.
    DrawTexture(crosshairT, GetMousePosition().x - crosshairT.width/2, GetMousePosition().y - crosshairT.height/2, BLACK);

    // Ending the render loop
    EndDrawing();
}

return 0;
}