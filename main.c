#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "world_types.h"

SDL_Window *win = NULL;
SDL_Renderer *artist = NULL;

int Init();
int Cleanup();

int main( int argc, char **argv ) {

  SDL_Event e;
  int quit = 0;
  Uint32 ms = SDL_GetTicks();

  if ( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) ) {
    printf( "SDL_Init Error: %s\n", SDL_GetError() );
    return 1;
  }

  //if all services initialize correctly we can start the game :)
  if ( Init() ) {

    //main game loop
    while( !quit ) {

      ms = SDL_GetTicks();

      while( (SDL_GetTicks() - ms) < 17 ) {
        SDL_PollEvent( &e );
        if(e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
          quit = !quit;
        }
        //update the game world until we are ready to draw
      }

      //draw the gameworld

    }


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
  } else {

    artist = SDL_CreateRenderer( win, -1, SDL_RENDERER_ACCELERATED |
				 SDL_RENDERER_PRESENTVSYNC );
    if ( artist == NULL ) {
      printf( "SDL_CreateRenderer Error: %s\n", SDL_GetError() );
      success = 0;
    }

  }

  return success;

}

int Cleanup() {

  int success = 1;

  SDL_DestroyWindow( win );

  SDL_DestroyRenderer( artist );

  return success;

}
