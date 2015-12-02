#include <SDL2/SDL.h>

int main(int argc, char **argv) {

  if(SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("SDL_Init Error %s\n", SDL_GetError());
    return 1;
  }

  SDL_Window *win = SDL_CreateWindow("Hello World", 100, 100,
				     640, 480, SDL_WINDOW_SHOWN);
  if(win == NULL) {
    printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
    return 1;
  }

}
