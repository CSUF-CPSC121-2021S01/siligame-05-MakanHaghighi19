#include "game.h"
#include "game_element.h"
#include "opponent.h"
#include "player.h"

int main() {
  Game gameInstance;
  gameInstance.Init();
  gameInstance.UpdateScreen();
  gameInstance.Start();
}
