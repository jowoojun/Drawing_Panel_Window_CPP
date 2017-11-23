#pragma once
#include<iostream>
#include<string>
using namespace std;

class Frame;
class Shape {
public:
  Shape(int x, int y, int sx, int sy);
  virtual void display() = 0;
  void add(Canvas);
protected:
  Frame *m_frame;
  int m_x, m_y;
  int m_xsize, m_ysize;
};