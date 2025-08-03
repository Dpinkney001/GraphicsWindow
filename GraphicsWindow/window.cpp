#include <SDL_render.h>
#include <SDL.h>
#include <stdio.h>

typedef struct {
	int x, y;
	short life;
	char* name;
} Man;		

int main(int argc, char* argv[]) {
	GameState gameState;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Surface* starSurface = NULL;

	SDL_Init(SDL_INIT_VIDEO);

	gameState.man.x = 320 - 40;
	gameState.man.y = 240 - 40;

	//Create an application window with the following settings:
	window = SDL_CreateWindow("Game Window",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640, 480,
		0
	);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//Load images and create rendering textures from them
	starSurface = IMG_Load("star.png");
	if(starSurface == NULL)
	{
		printf("Failed to load star image: %s\n", IMG_GetError());
		SDL_Quit();
		return 1;
	}

	gmaeState.star = SDL_CreateTextureFromSurface(renderer, starSurface);
	SDL_FreeSurface(starSurface);

	// the window is open: enter program loop ( see SDL_PollEvent)
	int done = 0;

	//Event loop
	while(!done)
	{ 
		done = processEvents(window, &gameState);

		//Render display
		doRender(render, &gameState);

		//don't burn up the CPU
		SDL_Delay(16); // roughly 60 FPS

	
	}
}