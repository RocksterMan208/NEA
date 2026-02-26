#pragma once

#include "raylib.h"
#include "raymath.h"
#include "settings.hpp"

class Player
{
    public:
        Vector2 pos = {screenWidth/2,screenHeight/2};
        int rotation = 0;

        Player();

        void update();
        void render();

    private:
        Rectangle playerRect = {pos.x, pos.y, 40,40};
};

class Bullet
{
    public:
        Bullet(Vector2 origin, Vector2 size, int speed);
};