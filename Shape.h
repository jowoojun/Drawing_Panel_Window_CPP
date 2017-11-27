#pragma once
#include<iostream>
#include<string>
using namespace std;

class Frame;
class Canvas;
class Shape {
public:
  Shape(int x, int y, int sx, int sy);  // initalize variables
  virtual void display() = 0;  // draw itself
  void setFrame(Frame *s);  // set Frame
  void setColor(COLORREF color);  // set Color
protected:
  Frame *m_frame;  // Frame for draw
  int m_x, m_y;  // x, y point (starting point)
  int m_xsize, m_ysize;  // width, height
  COLORREF m_color;  // color
};