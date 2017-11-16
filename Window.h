#pragma once
#include<iostream>
#include<string>
using namespace std;

class Window {
public:
    Window();  // Initialize variables
	Window(int x, int y, int sx, int sy);  // Initialize variables
    virtual void onMouseReleased(int x, int y) = 0;  // When mouse is released, it makes string output
    virtual void onMouseClick(int x, int y) = 0;  // When mouse is pressed, it makes string output.
protected:
    int m_x, m_y;  // starting point
    int m_xsize, m_ysize; // width, height
private:
};
