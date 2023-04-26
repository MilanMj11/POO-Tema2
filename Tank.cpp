#include "Tank.h"

Tank::Tank(const std::string &name, int speed, int year, int capacity, int ammunition, int armor) : Vehicle(name, speed, year, capacity),
                                                                                                    ammunition(ammunition),
                                                                                                    armor(armor) {}
