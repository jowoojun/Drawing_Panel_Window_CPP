#pragma once
#include <string>
using namespace std;

class Frame;
class Window {
public:
    // Initialize variables
	Window(int x, int y, int sx, int sy);
    // Initialize variables
	Window(string s, int x, int y, int sx, int sy);
    // Set m_frame to parameter
	void setFrame(Frame *);
    // Draw text content(text)
	void drawContent();
    // Whether there is click point (x,y) in this window or not
    // If it's in there, return true. If not, return false
	bool isInside(int x, int y);
    // Draw Window frame(Rectangle)
    virtual void display();
    // When mouse is pressed, it makes string output.
    virtual void onMouseClick(int x, int y);
    // When mouse is released, it makes string output
    virtual void onMouseReleased(int x, int y) = 0;
protected:
    int m_x, m_y;  // starting point
    int m_xsize, m_ysize; // width, height
	string m_text; // string in window
	Frame *m_frame; // frame including WIndows
private:
};
