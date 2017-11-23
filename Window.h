#pragma once
#include<iostream>
#include<string>
using namespace std;

class Frame;
class Container;
class Window {
public:
    Window();  // Initialize variables
	Window(int x, int y, int sx, int sy);  // Initialize variables
    Window(string s, int x, int y, int sx, int sy);  // Initialize variables
    void setContainer(Container * con);
    bool isInside(int x, int y); // Whether there is click point (x,y) in this Window or not. If it's in there, return true. If not, return false
    void setSize(int sx, int sy);
    void setFrame(Frame *f);
    string getTitle();
    virtual void onMouseClick(int x, int y) = 0;  // When mouse is pressed, it makes string output.
    virtual void onMouseReleased(int x, int y);
protected:
    int m_x, m_y;  // starting point
    int m_xsize, m_ysize; // width, height
    string m_text; // string in Window
    Container *m_container;
    Frame *m_frame;
private:
};
