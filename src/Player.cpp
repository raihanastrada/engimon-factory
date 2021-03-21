#include <stdio.h>
#include <string>
#include "Player.h"

using namespace std;

Player::Player() {

}
Player::Player(/* user defined */) {

}
void Player::Move(char direction) {
    if (direction == 'W' || direction == 'w') { this->Location.MoveUp(); }
    else if (direction == 'A' || direction == 'a') { this->Location.MoveLeft(); }
    else if (direction == 'S' || direction == 's') { this->Location.MoveDown(); }
    else if (direction == 'D' || direction == 'd') { this->Location.MoveRight(); }
}