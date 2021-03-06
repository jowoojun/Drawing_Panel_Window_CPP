#pragma once
#include "Window.h"
#include<iostream>
#include <list>
using namespace std;

class Shape;
class Rect;
class Canvas: public Window{
public :
  Canvas(); // Initialize variables
  void display();  // display all shapeList
  void add(Shape *s); // add Shape in shpaeList
  void setShapeType(int type); // set shape of Shape
  void setColor(COLORREF color); // set color of Shape
  void deleteShape(int x, int y);  // if you click the shape when you press the CTRL key, the clicked shape is removed.
  Shape* find(int x, int y);  // find Shape at clicked point
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
  virtual void onMouseReleased(int x, int y);  // When mouse is released, store ending point and make instance.
private:
  int m_startX, m_startY, m_width, m_height; // string point, ending point
  bool clicked = false;  // check whether shape is drawn
  list<Shape *>* shapeList; // shape's list
  int m_shapeType;  // shape of Shape
  COLORREF m_color; // color of Shape
};