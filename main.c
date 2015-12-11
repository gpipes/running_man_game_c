#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "world.h"

SDL_Window *win = NULL;
SDL_Renderer *artist = NULL;
world_queue world = NULL;

int Init();
int Cleanup();

void test_add_player(world_queue *world) {
  add_world_object(world, player_create_world_object(player_free, player_update, player_draw,
                  player_create("green.bmp", artist)));
}

int main( int argc, char **argv ) {

  SDL_Event e;
  int quit = 0;
  Uint32 now = 0, last = 0, elapsed = 0;

  if ( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) ) {
    printf( "SDL_Init Error: %s\n", SDL_GetError() );
    return 1;
  }

  if ( Init() ) {

    initialize_world_queue(&world);
    test_add_player(&world);
    last = SDL_GetTicks();

    while( !quit ) {

      now = SDL_GetTicks();
      elapsed += now - last;
      last = SDL_GetTicks();
      if ( elapsed >= 16 ) {
        printf("%d time elapse\n", elapsed);
        SDL_PollEvent( &e );
        if(e.key.keysym.sym == SDLK_ESCAPE) {
          quit = !quit;
        }
        elapsed = 0;
        SDL_RenderClear(artist);
        update_world(&world);
      }
      draw_world(&world);
      SDL_RenderPresent(artist);
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

    artist = SDL_CreateRenderer( win, -1, 0 );
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
