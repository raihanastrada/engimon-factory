#include <stdio.h>
#include "Point.h"

using namespace std;

// Default Constructor
Point::Point() : x(0), y(0) {}
// User-defined Constructor (int x and int y)
Point::Point(int in_x, int in_y) : x(in_x), y(in_y) {}
// Setter (x and y)
void Point::SetXY(int x, int y) { this->x = x; this->y = y; }
// Getter Point x
int Point::GetX() { return this->x; }
// Getter Point y
int Point::GetY() { return this->y; }
// Bergerak ke atas (y berkurang)
void Point::MoveUp() { this->y = y - 1; }
// Bergerak ke bawah (y bertambah)
void Point::MoveDown() { this->y = y + 1; }
// Bergerak ke kiri
void Point::MoveLeft() { this->x = x - 1; }
// Bergerak ke kanan
void Point::MoveRight() { this->x = x + 1; }