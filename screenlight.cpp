#include <SDL2/SDL.h>

int main(int argc, char* args[]) 
{
	//shouldn't matter
	int w = 1920;
	int h = 1080;

	SDL_Window* window = NULL;

	SDL_Surface* screen = NULL;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("ScreenLight",
				  SDL_WINDOWPOS_UNDEFINED,
				  SDL_WINDOWPOS_UNDEFINED,
				  w,
				  h,
				  SDL_WINDOW_FULLSCREEN);

	screen = SDL_GetWindowSurface(window);

	bool quit = false;
	Uint8 r = 255;
	Uint8 g = 255;
	Uint8 b = 255;
	int speed = 5;

	SDL_Event e;

	while (!quit)
	{
		while (SDL_PollEvent( &e ) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
					// CHANGING COLORS
					case SDLK_r:
						if (r+speed >= 255) {
							r = 255;
							break;
						}
						else {
							r += speed;
							break;
						}
					case SDLK_e:
						if (r-speed <= 0) {
							r = 0;
							break;
						}
						else {
							r -= speed;
							break;
						}
					case SDLK_g:
						if (g+speed >= 255) {
							g = 255;
							break;
						}
						else {
							g += speed;
							break;
						}
					case SDLK_f:
						if (g-speed <= 0) {
							g = 0;
							break;
						}
						else {
							g -= speed;
							break;
						}
					case SDLK_b:
						if (b+speed >= 255) {
							b = 255;
							break;
						}
						else {
							b += speed;
							break;
						}
					case SDLK_v:
						if (b-speed <= 0) {
							b = 0;
							break;
						}
						else {
							b -= speed;
							break;
						}

					// NUMBERS FOR SPEED
					case SDLK_1 ... SDLK_9:
						// lazy hackish solution! BOOOOO!
						speed = e.key.keysym.sym - '0';
						break;

					// Q FOR QUIT
					case SDLK_q:
						quit = true;
					default:
						break;

				}
			}
		}
		SDL_FillRect(screen, NULL,
			     SDL_MapRGB(screen->format, r, g, b));

		SDL_UpdateWindowSurface(window);
		SDL_Delay(100);
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
