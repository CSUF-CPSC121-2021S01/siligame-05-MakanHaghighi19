#include "opponent.h"
#include <iostream>

void Opponent::Draw(graphics::Image &gameboard) {
  gameboard.DrawLine(13 + x_, 11 + y_, 17 + x_, 11 + y_, 250, 0, 0);
  gameboard.DrawLine(12 + x_, 12 + y_, 18 + x_, 12 + y_, 250, 0, 0);
  gameboard.DrawLine(11 + x_, 13 + y_, 17 + x_, 14 + y_, 250, 0, 0);
  gameboard.DrawLine(13 + x_, 13 + y_, 14 + x_, 13 + y_, 0, 0, 0);
  gameboard.DrawRectangle(15 + x_, 13 + y_, 1, 1, 250, 0, 0);
  gameboard.DrawLine(16 + x_, 13 + y_, 17 + x_, 13 + y_, 0, 0, 0);
  gameboard.DrawLine(18 + x_, 13 + y_, 19 + x_, 13 + y_, 250, 0, 0);
  gameboard.DrawLine(9 + x_, 14 + y_, 13 + x_, 14 + y_, 68, 153, 168);
  gameboard.DrawLine(14 + x_, 14 + y_, 16 + x_, 14 + y_, 0, 0, 0);
  gameboard.DrawLine(17 + x_, 14 + y_, 21 + x_, 14 + y_, 68, 153, 168);
  gameboard.DrawLine(12 + x_, 15 + y_, 18 + x_, 15 + y_, 68, 153, 168);
  gameboard.DrawRectangle(12 + x_, 16 + y_, 1, 1, 68, 153, 168);
  gameboard.DrawLine(14 + x_, 16 + y_, 16 + x_, 16 + y_, 68, 153, 168);
  gameboard.DrawRectangle(18 + x_, 16 + y_, 1, 1, 68, 153, 168);
}

void OpponentProjectile::Draw(graphics::Image &gameboard) {
  gameboard.DrawRectangle(3 + x_, 0 + y_, 1, 1, 250, 0, 0);
  gameboard.DrawLine(2 + x_, 1 + y_, 2 + x_, 2 + y_, 250, 0, 0);
  gameboard.DrawLine(4 + x_, 1 + y_, 4 + x_, 2 + y_, 250, 0, 0);
  gameboard.DrawLine(1 + x_, 3 + y_, 1 + x_, 4 + y_, 250, 0, 0);
  gameboard.DrawLine(5 + x_, 3 + y_, 5 + x_, 4 + y_, 250, 0, 0);
  gameboard.DrawLine(2 + x_, 5 + y_, 4 + x_, 5 + y_, 250, 0, 0);
  gameboard.DrawLine(2 + x_, 3 + y_, 2 + x_, 4 + y_, 178, 3, 3);
  gameboard.DrawLine(4 + x_, 3 + y_, 4 + x_, 4 + y_, 178, 3, 3);
  gameboard.DrawLine(3 + x_, 1 + y_, 3 + x_, 3 + y_, 178, 3, 3);
  gameboard.DrawRectangle(3 + x_, 4 + y_, 1, 1, 0, 0, 0);
}

void Opponent::Move(const graphics::Image &gameboard) {
  if (IsOutOfBounds(gameboard)) {
    is_active = false;
  } else {
    SetX(x_ + 1);
    SetY(y_ + 1);
  }
}

void OpponentProjectile::Move(const graphics::Image &gameboard) {
  if (IsOutOfBounds(gameboard)) {
    is_active = false;
  } else {
    SetX(x_ + 1);
    SetY(y_ + 3);
  }
}

std::unique_ptr<OpponentProjectile> Opponent::LaunchProjectile() {
  blaster_counter += 1;
  if (blaster_counter % 20 == 0) {
    std::unique_ptr<OpponentProjectile> new_blaster =
        std::make_unique<OpponentProjectile>(GetX(), GetY());
    return std::move(new_blaster);
  } else {
    return nullptr;
  }
}
