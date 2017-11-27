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
    bool isInside(int x, int y); // Whether there is click point (x,y) in this Window or not. If it's in there, return true. If not, return false
    void setContainer(Container * con); // set container that they are contained 
    void setSize(int sx, int sy);  // set Window Size
    void setFrame(Frame *f);  // set Frame
    string getTitle();  // get m_text
    virtual void onMouseClick(int x, int y) = 0;  // When mouse is pressed
    virtual void onMouseReleased(int x, int y);  // When mouse is released
protected:
    int m_x, m_y;  // starting point
    int m_xsize, m_ysize; // width, height
    string m_text; // string in Window
    Container *m_container;
    Frame *m_frame;
private:
};
