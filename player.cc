#include "player.h"
#include <iostream>
#include <string>
#include "cpputils/graphics/image.h"

void Player::Draw(graphics::Image &gameboard) {
  gameboard.DrawRectangle(23 + x_, 13 + y_, 2, 21, 26, 86, 184);
  gameboard.DrawRectangle(22 + x_, 15 + y_, 4, 18, 26, 86, 184);
  gameboard.DrawRectangle(23 + x_, 34 + y_, 2, 2, 0, 0, 0);
  gameboard.DrawRectangle(21 + x_, 18 + y_, 1, 8, 0, 0, 0);
  gameboard.DrawRectangle(19 + x_, 19 + y_, 2, 7, 0, 0, 0);
  gameboard.DrawRectangle(17 + x_, 20 + y_, 2, 7, 0, 0, 0);
  gameboard.DrawRectangle(16 + x_, 21 + y_, 1, 6, 0, 0, 0);
  gameboard.DrawRectangle(15 + x_, 22 + y_, 1, 5, 0, 0, 0);
  gameboard.DrawRectangle(14 + x_, 23 + y_, 1, 5, 0, 0, 0);
  gameboard.DrawRectangle(13 + x_, 25 + y_, 1, 4, 0, 0, 0);
  gameboard.DrawRectangle(26 + x_, 18 + y_, 1, 8, 0, 0, 0);
  gameboard.DrawRectangle(27 + x_, 19 + y_, 2, 7, 0, 0, 0);
  gameboard.DrawRectangle(29 + x_, 20 + y_, 2, 7, 0, 0, 0);
  gameboard.DrawRectangle(31 + x_, 21 + y_, 1, 6, 0, 0, 0);
  gameboard.DrawRectangle(32 + x_, 22 + y_, 1, 5, 0, 0, 0);
  gameboard.DrawRectangle(33 + x_, 23 + y_, 1, 5, 0, 0, 0);
  gameboard.DrawRectangle(34 + x_, 25 + y_, 1, 4, 0, 0, 0);
  gameboard.DrawLine(19 + x_, 26 + y_, 20 + x_, 26 + y_, 250, 0, 0);
  gameboard.DrawLine(15 + x_, 27 + y_, 17 + x_, 27 + y_, 250, 0, 0);
  gameboard.DrawLine(27 + x_, 26 + y_, 28 + x_, 26 + y_, 250, 0, 0);
  gameboard.DrawLine(30 + x_, 27 + y_, 32 + x_, 27 + y_, 250, 0, 0);
}

void PlayerProjectile::Draw(graphics::Image &gameboard) {
  gameboard.DrawLine(2 + x_, 1 + y_, 4 + x_, 1 + y_, 0, 105, 255);
  gameboard.DrawLine(1 + x_, 2 + y_, 1 + x_, 3 + y_, 0, 105, 255);
  gameboard.DrawLine(5 + x_, 2 + y_, 5 + x_, 3 + y_, 0, 105, 255);
  gameboard.DrawLine(2 + x_, 2 + y_, 2 + x_, 3 + y_, 37, 154, 253);
  gameboard.DrawLine(4 + x_, 2 + y_, 4 + x_, 3 + y_, 37, 154, 253);
  gameboard.DrawLine(3 + x_, 3 + y_, 3 + x_, 5 + y_, 37, 154, 253);
  gameboard.DrawLine(2 + x_, 4 + y_, 2 + x_, 5 + y_, 0, 105, 255);
  gameboard.DrawLine(4 + x_, 4 + y_, 4 + x_, 5 + y_, 0, 105, 255);
  gameboard.DrawRectangle(3 + x_, 2 + y_, 1, 1, 72, 186, 253);
  gameboard.DrawRectangle(3 + x_, 6 + y_, 1, 1, 0, 105, 255);
}

void Player::Move(const graphics::Image &gameboard) {}

void PlayerProjectile::Move(const graphics::Image &gameboard) {
  if (IsOutOfBounds(gameboard)) {
    is_active = false;
  } else {
    SetX(x_ + 1);
    SetY(y_ - 3);
  }
}
