#pragma once
#include "Window.h"
#include<iostream>
using namespace std;

class Canvas: public Window{
public :
  Canvas(Frame *f); // Initialize variables
  virtual void onMouseReleased(int x, int y);  // When mouse is released, it makes string output
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
};