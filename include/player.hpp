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
        Vector2 velocity = {0,0};

        int rotation = 0;

        Player();

        void update();
        void render();
        void shoot();

    private:

    float health = 100;

     Font defaultFont = LoadFont(fontPath.c_str());

    Texture2D playerIconT;

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
        Rectangle square = {pos.x, pos.y, bulletWidth, bulletHeight};
        DrawRectanglePro(square, {bulletWidth/2, bulletHeight/2}, -rotation, GRAY);
    }
};