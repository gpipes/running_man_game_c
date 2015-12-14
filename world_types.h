#ifndef ___WORLD_TYPES_H
#define ___WORLD_TYPES_H

#define PLAYER_SIZE 64
#define JUMP_HEIGHT 64
#define HURDLE_SIZE 64

#include <SDL2/SDL.h>

//lower level data type includes
#include "list.h"

typedef struct PLAYER {

  SDL_Rect loc;
  SDL_Rect current_sprite_loc;
  struct JUMP {
    short int is_jumping;
    Uint32 started_jump;
  } jump;
  Uint32 last_sprite_change;
  SDL_Texture *sprite_sheet;

} player;

typedef SDL_Rect hurdle;

typedef list hurdles_queue;

typedef struct HURDLES_MANAGER {

  SDL_Texture *sprite_sheet;
  SDL_Rect current_sprite_loc;
  hurdles_queue all_hurdles;

  //last generated hurdle and generation interval
  Uint32 generate_window[2];
  player *p_player;

} hurdles_manager;

typedef union OBJECT {

  player *p_player;
  hurdles_manager *p_hurdles_manager;

} object;

typedef struct WORLD_OBJECT {

  //information on how to free the obj
  void (*free_func)( object p_obj );

  //how to update the obj
  void (*update_func)( object p_obj, SDL_Event *e, Uint32 now );

  //how to draw the obj
  void (*draw_func)( object p_obj, SDL_Renderer *renderer );

  object p_obj;

} world_object;

typedef node world_node;

typedef list world_queue;

#endif
