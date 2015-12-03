#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include <SDL2/SDL.h>

SDL_Window *win = NULL;
SDL_Renderer *artist = NULL;

int Init();
int Cleanup();

int main( int argc, char **argv ) {
  
  if ( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) ) {
    printf( "SDL_Init Error: %s\n", SDL_GetError() );
    return 1;
  }

  //if all services initialize correctly we can start the game :)
  if ( Init() ) {

    

  }

  Cleanup();
  SDL_Quit();
  return 0;
  
}

int Init() {

  int success = 1;

  win = SDL_CreateWindow( "Running Man", SDL_WINDOWPOS_UNDEFINED,
			  SDL_WINDOWPOS_UNDEFINED, 480, 640,
			  SDL_WINDOW_FULLSCREEN );
  if ( win == NULL ) {
    printf( "SDL_CreateWindow Error: %s\n", SDL_GetError() );
    success = 0;
  }

  artist = SDL_CreateRenderer( win, -1, SDL_RENDERER_ACCELERATED |
			       SDL_RENDERER_PRESENTVSYNC );
  if ( artist == NULL ) {
    printf( "SDL_CreateRenderer Error: %s\n", SDL_GetError() );
    success = 0;
  }
  

  return success;
  
}

int Cleanup() {

  int success = 1;

  SDL_DestroyWindow( win );

  SDL_DestroyRenderer( artist );

  return success;

}
