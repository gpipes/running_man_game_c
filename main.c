#define bint int

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>



SDL_Window *win = NULL;
SDL_Surface *screen_surface = NULL;
SDL_Surface *hello_surface = NULL;

bint init() {
  int success = 1;

  if (SDL_Init(SDL_INIT_VIDEO)) {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    success = 0;
  } else {
    win = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED,
			   SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (win == NULL) {
      printf("SDL_CreateWindow Eroor: %s\n", SDL_GetError());
      success = 1;
    } else {
      screen_surface = SDL_GetWindowSurface(win);
    }
    
  }

  return success;
}

bint load_media() {

  int success = 1;

  hello_surface = SDL_LoadBMP("hello.bmp");

  if (hello_surface == NULL) {
    printf("SDL_LoadBMP Error: %s\n", SDL_GetError());
    success = 0;
  }

  return success;
  
}

bint close() {

  SDL_FreeSurface(hello_surface);
  hello_surface = NULL;

  SDL_DestroyWindow(win);
  win = NULL;

  SDL_Quit();

}

int main(int argc, char **argv) {

  if (!init()) {
    close();
    printf("Failed to init\n");
    return 1;
  }
  if (!load_media()) {
    close();
    printf("Failed to load media\n");
    return 1;
  } else {
    //blitting imposes one surface on another
    SDL_BlitSurface( hello_surface, NULL, screen_surface, NULL );
    SDL_UpdateWindowSurface( win );
  }
  SDL_Delay( 2000 );

  close();

  return 0;
}
