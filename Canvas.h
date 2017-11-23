#pragma once
#include "Window.h"
#include<iostream>
using namespace std;

class Canvas: public Window{
public :
  Canvas(); // Initialize variables
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
  virtual void onMouseReleased(int x, int y);

private:
  int pointX, pointY, releaseX, releaseY;
  bool clicked = false;
};