#ifndef ___PLAYER_H
#define ___PLAYER_H

#include "world_types.h"

player* player_create(const char* sprite_sheet, SDL_Renderer *parent);

void player_draw(object p_obj, SDL_Renderer *renderer);

void player_update(object p_obj, SDL_Event *e, Uint32 now);

void player_free(object p_obj);

world_object *player_create_world_object(void (*free_funct)(object), void (*update_func)(object,SDL_Event*,Uint32),
                                          void (*draw_func)(object,SDL_Renderer *), player *p_player);

#endif
