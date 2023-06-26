#pragma once
#include "SDL.h"
#include <iostream>
using namespace std;

// Destroys renderer and window then quits SDL
void TX_WindowDest(SDL_Renderer* renderer, SDL_Window* window);

// Returns a RectRectFromImage
SDL_Rect TX_RectFromImage(float SCREEN_WIDTH, float SCREEN_HEIGHT, SDL_Surface* imageSurface, float widthMult, float heightMult, float x, float y);

// Destroys renderer and window then quits SDL
void TX_RenderImage(SDL_Renderer* renderer, float SCREEN_WIDTH, float SCREEN_HEIGHT, char* IMAGE_PATH, float widthMult, float heightMult, float x, float y);