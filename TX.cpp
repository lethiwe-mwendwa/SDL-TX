#include "TX.h"

// Destroys renderer and window then quits SDL
void TX_WindowDest(SDL_Renderer* renderer, SDL_Window* window) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

// Returns a RectRectFromImage
SDL_Rect TX_RectFromImage(float SCREEN_WIDTH, float SCREEN_HEIGHT, SDL_Surface* imageSurface, float widthMult, float heightMult, float x, float y) {
	int imageWidth = imageSurface->w;
	int imageHeight = imageSurface->h;
	SDL_Rect rect{};

	if (SCREEN_HEIGHT > SCREEN_WIDTH) {
		rect.w = SCREEN_WIDTH * heightMult;
		rect.h = (rect.w * imageHeight) / imageWidth;
	}
	else {
		rect.h = SCREEN_HEIGHT * widthMult;
		rect.w = (rect.h * imageWidth) / imageHeight;
	}

	rect.x = x;
	rect.y = y;

	return rect;
}

// Destroys renderer and window then quits SDL
void TX_RenderImage(SDL_Renderer* renderer, float SCREEN_WIDTH, float SCREEN_HEIGHT, char* IMAGE_PATH, float widthMult, float heightMult, float x, float y) {

	SDL_Surface* imageSurface = NULL;
	imageSurface = SDL_LoadBMP(IMAGE_PATH);
	if (NULL == imageSurface) {
		cout << "SDL error BRO WHAT" << SDL_GetError();
	}

	SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
	SDL_Rect rect = TX_RectFromImage(SCREEN_WIDTH, SCREEN_HEIGHT, imageSurface, widthMult, heightMult, x, y);

	SDL_FreeSurface(imageSurface);

	SDL_RenderCopy(renderer, imageTexture, NULL, &rect);
	SDL_DestroyTexture(imageTexture);
	SDL_RenderPresent(renderer);

}