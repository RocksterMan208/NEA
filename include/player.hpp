#pragma once

#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include <vector>

#include "settings.hpp"


class Player
{
    public:
        Vector2 pos = {screenWidth/2,screenHeight/2};
        Vector2 direction = {0,0};

        int rotation = 0;

        Player();

        void update();
        void render();
        void shoot();

    private:

};


struct bullet
{
    Vector2 size;
    Vector2 pos;
    Vector2 speed;
    
    bool active = true;
    float rotation;

    void render()
    {
        Rectangle square = {pos.x, pos.y, 10,10};
        DrawRectanglePro(square, {5,5}, -rotation, PURPLE);
    }
};