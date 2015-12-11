#include "world.h"

int initialize_world_queue(world_queue *w) {
  return init_list(w);
}

int add_world_object(world_queue *w, world_object *o) {
  return append_node( w, (void *) o );
}

world_object *remove_world_object(world_queue *w) {
  world_object *obj = (world_object *)delete_first_node(w);
  return obj;
}

void draw_world(world_queue *w, SDL_Renderer *renderer) {

  world_object *p_w_obj;
  world_node *curr_node;
  //in an empty world nothing is drawn
  if (*w == NULL)
    return;

  curr_node = *w;

  while (curr_node != NULL) {

    world_object *p_w_obj = (world_object *)curr_node->data;
    p_w_obj->draw_func( p_w_obj->p_obj, renderer );

    curr_node = curr_node->next;

  }

  return;

}

void update_world(world_queue *w) {
  return;
}

void free_world(world_queue *w) {

  world_object *p_w_obj;
  world_node *p_curr_node;
  world_node *p_free_node;
  //in an empty world nothing is drawn
  if (*w == NULL)
    return;

  p_curr_node = *w;

  while ( (p_w_obj = (world_object *)delete_first_node(w)) != NULL ) {
    p_w_obj->free_func( p_w_obj->p_obj );
    free(p_w_obj);
  }

  return;

}
