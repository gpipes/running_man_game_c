#ifndef ___WORLD_TYPES_H
#define ___WORLD_TYPES_H

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

  //renderer will no be freed when freeing
  //player it is assumed that this is just
  //a seperate parent renderer
  SDL_Renderer *renderer;

} player;

typedef union OBJECT {

  player *p_player;

} object;

typedef struct WORLD_OBJECT {

  //information on how to free the obj
  void (*free_func)( object p_obj );

  //how to update the obj
  void (*update_func)( object p_obj, SDL_Event *e, Uint32 now );

  //how to draw the obj
  void (*draw_func)( object p_obj );

  object p_obj;

} world_object;

typedef node world_node;

typedef list world_queue;

#endif
