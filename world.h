#ifndef ___WORLD_H
#define ___WORLD_H

#include "world_types.h"
#include "player.h"

int initialize_world_queue(world_queue *w);

int add_world_object(world_queue *w, world_object *o);

world_object *remove_world_object(world_queue *w);

void draw_world(world_queue *w, SDL_Renderer *renderer);

void update_world(world_queue *w);

void free_world(world_queue *w);

#endif
