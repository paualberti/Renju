#ifndef Runner_h_
#define Runner_h_

#include "Game.h"
#include "Square.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <array>

typedef struct Runner {
  Game *game;
  std::array<SDL_Rect, 4> corners; // indicate turn
  SDL_Renderer *renderer;
  SDL_Window *window;
  int running;
  std::array<int, SIZE * SIZE> ignore; // ignrore out of bounds moves
} Runner;

Runner *CreateRunner();
void Runner_Events();
void Runner_Render();
void Runner_Update();

#endif // Runner_h_
