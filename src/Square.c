#include "Square.h"
#include <SDL2/SDL_pixels.h>

Square *CreateSquare(const int x, const int y, const int side) {
  Square *square;
  square->color.r = 0;
  square->color.g = 0;
  square->color.b = 0;
  square->color.a = 255;
  square->clicked = 0;
  square->side = side;
  square->pos.x = x;
  square->pos.y = y;
  return square;
}

