#ifndef _POINT_H_
#define _POINT_H_

#include <stdio.h>

using namespace std;

class Point {
    private:
        int x; // Koordinat x
        int y; // Koordinat y
    public:
        Point(); // Default Constructor
        Point(int x, int y); // User-defined Constructor
        void SetXY(int x, int y); // Setter x dan y
        int GetX(); // Getter x
        int GetY(); // Getter y
        void MoveUp();
        void MoveDown();
        void MoveLeft();
        void MoveRight();
};

#endif