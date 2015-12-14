#include "hurdles_manager.h"



void move_hurdles_forward(hurdles_queue *p_hurdles_queue) {

  node *p_curr_node = *p_hurdles_queue;
  hurdle *p_hurdle;

  if(*p_hurdles_queue == NULL)
    return;

  p_hurdle = (hurlde *)p_curr_node->data;

  if((int32)p_hurdle->x < 0) {
    delete_first_node(p_hurdles_queue);
    free(p_hurdle);
    p_curr_node = *p_hurdles_queue;
  }

  while(p_curr_node != NULL) {

    p_hurdle = (hurlde *)p_curr_node->data;
    p_hurdle->x -= 2;
    p_curr_node = p_curr_node->next;

  }

  return;

}

void hurdle_append(hurdles_manager *p_hurdles_manager, SDL_Renderer 8renderer) {

    int ren_w = 0, ren_h = 0;
    hurdle *new_hurdle = (hurdle *)malloc(sizeof(hurdle));
    SDL_GetRendererOutputSize(renderer, &ren_w, &ren_h);

    new_hurdle->x = ren_w;
    if( p_hurdles_manager->player->jump.is_jumping ) {

      new_hurdle->y = p_hurdles_manager->player->loc.y + JUMP_HEIGHT;

    } else {

      new_hurdle->y = p_hurdles_manager->player->loc.y;

    }
    new_hurdle->w = HURDLE_SIZE;
    new_hurdle->h = HURDLE_SIZE;

    append_node(&p_hurdles_manager->all_hurdles, (void *)new_hurdle);

    return;

}

void generate_hurdle(hurdles_manager *p_hurdles_manager, SDL_Renderer *renderer) {

  if(SDL_GetTicks() - p_hurdles_manager->generate_window[0] > p_hurdles_manager->generate_window[1]) {
    hurdle_append(p_hurdles_manager, renderer);
  }

}

hurdle *get_first_hurdle_address_from_queue(hurdles_queue *h) {

  node *p_curr_node = *h;
  hurdle *p_hurdle;

  if(p_curr_node == NULL)
    return NULL;

  p_hurdle = (hurdle *)p_curr_node->data;

  return p_hurdle;

}

void hurdles_queue_free(hurdles_queue *h) {

  hurdle *p_hurdle;

  if( *h == NULL )
    return;

  while( (p_hurdle = (hurdle *)delete_first_node(h))  != NULL) {

    free(p_hurdle);

  }

  return;

}

void hurdles_manager_free(object p_obj) {

  hurdles_manager *p_h_manager = p_obj.p_hurdles_manager;
  SDL_DestroyTexture(p_h_manager->sprite_sheet);
  hurdles_queue_free(&(p_h_manager->all_hurdles));
  return;

}

void hurdles_manager_update(object p_obj, SDL_Event *e, Uint32 now) {

  hurdles_manager *p_h_manager = p_obj.p_h_manager;

  move_hurdles_forward(p_h_manager->all_hurdles);

}

void hurdles_manager_draw(object p_obj, SDL_Renderer *renderer) {

  hurdles_manager *p_h_manager = p_obj.p_hurdles_manager;
  hurdles_queue h_queue = p_h_manager->all_hurdles;
  hurdle *p_hurdle;

  generate_hurdle(p_h_manager, renderer);

  while(h_queue != NULL) {

    p_hurdle = get_first_hurdle_address_from_queue(h_queue);
    SDL_RenderCopy(renderer, p_h_manager->sprite_sheet,
                  &p_h_manager->current_sprite_loc, p_hurdle);
    h_queue = h_queue->next;

  }

  return;

}
