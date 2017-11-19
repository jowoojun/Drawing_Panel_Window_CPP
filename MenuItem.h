#pragma once
#include<iostream>
#include "Window.h"
using namespace std;

class Frame;
class MenuItem :public Window{
public:
  MenuItem(string s);
  void display(Frame *f);
  void setX(int x);
  void setY(int y);
  MenuItem* isInside(int x, int y);
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
private:
};