#include <stdio.h>
#include "Point.h"

using namespace std;

Point::Point() : x(0), y(0) {} // Default Constructor
Point::Point(int in_x, int in_y) : x(in_x), y(in_y) {} // User-defined Constructor (int x and int y)
void Point::SetXY(int x, int y) { this->x = x; this->y = y; } // Setter (x and y)
int Point::GetX() { return this->x; } // Getter x
int Point::GetY() { return this->y; } // Getter y
void Point::MoveUp() { this->y = y + 1; } // Bergerak ke atas
void Point::MoveDown() { this->y = y - 1; } // Bergerak ke bawah
void Point::MoveLeft() { this->x = x - 1; } // Bergerak ke kiri
void Point::MoveRight() { this->x = x + 1; } // Bergerak ke kanan