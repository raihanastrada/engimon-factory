#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;

Player::Player() { }
Player::Player(string name) {
    this->PlayerName = name;
}
Player::~Player() { }
void Player::Move(char direction) {
    this->EngimonLocation = this->Location; // Active Engimon berpindah tempat ke lokasi Player
    if (direction == 'W' || direction == 'w') { this->Location.MoveUp(); }
    else if (direction == 'A' || direction == 'a') { this->Location.MoveLeft(); }
    else if (direction == 'S' || direction == 's') { this->Location.MoveDown(); }
    else if (direction == 'D' || direction == 'd') { this->Location.MoveRight(); }
}
Point Player::getLocation() { return this->Location; }
Point Player::getEngimonLocation() { return this->EngimonLocation; }