#ifndef ___HURDLES_MANAGER_H
#define ___HURDLES_MANAGER_H

#include "world_types.h"

void hurdles_queue_free(hurdles_queue *h);

void hurdles_manager_free(object p_obj);

void hurdles_manager_update(object p_obj, SDL_Event *e, Uint32 now);

void hurdles_manager_draw(obj p_obj, SDL_Renderer *renderer);

#endif
