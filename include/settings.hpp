#pragma once
#include "raylib.h"
#include <string>

constexpr int screenWidth = 800;
constexpr int screenHeight = 600;

constexpr int playerAccel = 900;
constexpr float playerFriction = 0.85;
constexpr int playerMaxSpeed = 200;

constexpr int bulletSpeed = 350;
constexpr int bulletWidth = 15;
constexpr int bulletHeight = 5;

const std::string playerIconPath = "resources/player.png";
const std::string crosshairIconPath = "resources/crosshair.png";

const std::string fontPath = "resources/AdwaitaMono-Regular.ttf";