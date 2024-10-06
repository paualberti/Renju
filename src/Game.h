#ifndef Game_h_
#define Game_h_

#include "Square.h"
#include <array>
#include <functional>
#include <vector>
#define TARGET 5

typedef struct Counter {
  int count_b1; // count till break1
  int count_b2; // count till break2
  int break1;   // first blank space
  int break2;   // second blank space
} Counter;

Counter CreateCounter(const int initial_count_b1, const int initial_count_b2);
Counter Counter_CountDir(const int pos, const int step,
                         std::function<bool(int)> checkBoundary1,
                         std::function<bool(int)> checkBoundary2);
std::array<Counter, 4> Counter_CountAll(const int pos);

typedef struct Game {
  int game_end;
  int turn; // black, white, null
  std::array<std::array<Square *, SIZE>, SIZE> grid;
  std::vector<int> played; // played moves
  std::vector<int> undone; // undone moves
} Game;

Game *CreateGame();
bool Game_GameEnd(const int pos);
bool Game_IsOverTarget(const int pos);
bool Game_RedoLast();
bool Game_UndoLast();
int Game_CountFours(const int pos);
int Game_CountThree(const int pos);
int Game_CountTwo(const int pos);

#endif // Game_h_
