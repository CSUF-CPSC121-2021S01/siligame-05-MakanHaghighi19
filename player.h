#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"

class Player : public GameElement {
 public:
  Player() : GameElement(0, 0, 38, 38) {}
  Player(const int &x, const int &y) : GameElement(x, y, 38, 38) {}

  void Draw(graphics::Image &gameboard) override;
  void Move(const graphics::Image &gameboard) override;
};

class PlayerProjectile : public GameElement {
 public:
  PlayerProjectile() : GameElement(0, 0, 7, 7) {}
  PlayerProjectile(const int &x, const int &y) : GameElement(x, y, 7, 7) {}

  void Draw(graphics::Image &gameboard) override;
  void Move(const graphics::Image &gameboard) override;
};
#endif
