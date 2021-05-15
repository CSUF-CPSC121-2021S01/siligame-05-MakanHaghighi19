#ifndef OPPONENT_H
#define OPPONENT_H
#include <iostream>
#include <string>
#include "cpputils/graphics/image.h"
#include "game_element.h"

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile() : GameElement(0, 0, 7, 7) {}
  OpponentProjectile(const int &x, const int &y) : GameElement(x, y, 7, 7) {}
  void Draw(graphics::Image &gameboard) override;
  void Move(const graphics::Image &gameboard) override;
};

class Opponent : public GameElement {
 public:
  Opponent() : GameElement(0, 0, 38, 38) {}
  Opponent(const int &x, const int &y) : GameElement(x, y, 38, 38) {}
  void Draw(graphics::Image &gameboard) override;
  void Move(const graphics::Image &gameboard) override;
  std::unique_ptr<OpponentProjectile> LaunchProjectile();

 private:
  int blaster_counter = 0;
};

#endif
