#include "Player.h"

Player::Player(): scores(0), missShots(0), nick("-") {}

Player::Player(int s, int m, const std::string& n): scores(s), missShots(m), nick(n) {}

Player::Player(const std::string& n): Player(0,0,n) {}