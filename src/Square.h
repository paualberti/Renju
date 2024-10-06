#ifndef Square_h_
#define Square_h_

#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#define SIZE 15

typedef struct Position {
  int x, y;
} Position;

typedef struct Square {
  SDL_Color color;
  int clicked;
  int side;  // dimension of space in grid
  int state; // which player it belongs to
  Position pos;
} Square;

Square *CreateSquare(const int x, const int y, const int side);
void Square_PlacePiece(const int state);
void Square_Render(SDL_Renderer *renderer);

#endif // Square_h_
