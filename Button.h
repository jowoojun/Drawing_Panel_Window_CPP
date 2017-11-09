#pragma once
#include "Window.h"
#include<iostream>

class Button : public Window {
public :
  Button(std::string s, int x, int y, int sx, int sy);
  virtual void display();
  virtual void onMouseClick(int x, int y);
private:
  int m_count = 0;
};