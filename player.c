#include "player.h"

player *player_create(const char* sprite_sheet, SDL_Renderer *renderer) {

  int ren_w = 0, ren_h = 0;

  SDL_GetRendererOutputSize( renderer, &ren_w, &ren_h );

  SDL_Surface *surface = SDL_LoadBMP(sprite_sheet);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);

  player *temp = (player *)malloc(sizeof(player));

  temp->loc.x = 0;
  temp->loc.y = ( (ren_h/2) - PLAYER_SIZE );
  temp->loc.w = PLAYER_SIZE;
  temp->loc.h = PLAYER_SIZE;

  temp->current_sprite_loc.x = 0;
  temp->current_sprite_loc.y = 0;
  temp->current_sprite_loc.w = 32;
  temp->current_sprite_loc.h = 32;

  temp->jump.is_jumping = 0;

  Uint32 now = SDL_GetTicks();

  temp->jump.started_jump = now;
  temp->last_sprite_change = now;

  temp->sprite_sheet = texture;
  temp->renderer = renderer;

  return;

}

void player_draw(object p_obj) {

  player *player = p_obj.p_player;
  SDL_RenderCopy(player->renderer, player->sprite_sheet, player->current_sprite_loc, player->loc);
  return;

}

void player_free(object p_obj) {
  player *player = p_obj.p_player;
  SDL_DestroyTexture(player->sprite_sheet);
  free(player);
}

void player_update(object p_obj, SDL_Event *e, Uint32 now) {
  return;
}
