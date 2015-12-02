#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char **argv) {

  if(SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("SDL_Init Error %s\n", SDL_GetError());
    return 1;
  }
  //create a window (win is a pointer to the struct)
  SDL_Window *win = SDL_CreateWindow("Hello World", 100, 100,
				     640, 480, SDL_WINDOW_SHOWN
				               | SDL_WINDOW_FULLSCREEN);
  if(win == NULL) {
    printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }
  //create a renderer
  //ren is a pointer to it and it is registered with win
  //used to draw on the window
  SDL_Renderer *ren = SDL_CreateRenderer(win, -1,
					 SDL_RENDERER_ACCELERATED |
					 SDL_RENDERER_PRESENTVSYNC);
  if(ren == NULL) {
    SDL_DestroyWindow(win);
    printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  //in order to load images you need to load it into memory
  //then onto the rendering platform

  char *image_path = "./hello.bmp";
  printf("test: image_path = %d\n", image_path);
  
  
  SDL_Surface *bmp = SDL_LoadBMP(image_path);
  if(bmp == NULL) {
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    printf("SDL_LoadBMP Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
  SDL_FreeSurface(bmp);
  if(tex == NULL) {
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }
  for (int i = 0 ; i < 3 ; ++i) {
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, tex, NULL, NULL);
    SDL_RenderPresent(ren);
    SDL_Delay(10000);
  }
  SDL_DestroyTexture(tex);
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();
}
