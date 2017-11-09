#pragma once
#include <string>
using namespace std;

class Frame;
class Window {
public:
	Window(int x, int y, int sx, int sy);  // Initialize variables
	Window(string s, int x, int y, int sx, int sy);  // Initialize variables
    ~Window();  // remove Window until m_next is null
	void setFrame(Frame *);  // Set m_frame to parameter
	void drawContent();  // Draw text content(text)
	Window* isInside(int x, int y);  // Whether there is click point (x,y) in this window or not. If it's in there, return this. If not, find m_next
    virtual void display();  // Draw Window frame(Rectangle)
    virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
    virtual void onMouseReleased(int x, int y) = 0;  // When mouse is released, it makes string output
    void setNext(Window* w);  // set next Window
protected:
    int m_x, m_y;  // starting point
    int m_xsize, m_ysize; // width, height
    Window *m_next;  // next Window
	string m_text; // string in Window
	Frame *m_frame; // frame including WIndows
private:
};
