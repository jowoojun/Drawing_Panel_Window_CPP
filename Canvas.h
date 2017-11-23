#pragma once
#include "Window.h"
#include<iostream>
using namespace std;

class Shape;
class Rect;
class Canvas: public Window{
public :
  Canvas(); // Initialize variables
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
  virtual void onMouseReleased(int x, int y);
  void display();
private:
  int pointX, pointY, releaseX, releaseY;
  bool clicked = false;
  list<Shape *>* shapeList;
};