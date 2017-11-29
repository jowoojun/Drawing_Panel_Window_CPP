#pragma once
#include<iostream>
#include<string>
using namespace std;

class Frame;
class Canvas;
class Shape {
public:
  Shape(int x, int y, int w, int h);  // initalize variables
  void setFrame(Frame *s);  // set Frame
  void setColor(COLORREF color);  // set Color
  void moveto(int w, int h);  // move shape
  virtual bool isInside(int x, int y);  // Whether there is click point (x,y) in this Window or not. If it's in there, return true. If not, return false
  virtual void display() = 0;  // draw itself
protected:
  Frame *m_frame;  // Frame for draw
  int m_startX, m_startY;  // x, y poidisplaunt (starting point)
  int m_width, m_height;  // width, height
  COLORREF m_color;  // color
};