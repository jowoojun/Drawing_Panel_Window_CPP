#pragma once
#include "Window.h"
#include<iostream>

class MenuBar : public Window {
public:
  // Initialize variables
  MenuBar();
  // When mouse is clicked, it makes output that is string.
  virtual void onMouseReleased(int x, int y);
  virtual void onMouseClick(int x, int y);
private:
};