#pragma once
#include<iostream>
#include "Window.h"
using namespace std;

class Frame;
class MenuItem :public Window{
public:
  MenuItem(string s);  // Initialize variables
  void display(Frame *f);  // draw MenuItem
  void setSize(int x, int y); // set Size of MenuItem
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
private:
};