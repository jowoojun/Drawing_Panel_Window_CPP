#pragma once
#include "Window.h"
#include<iostream>
#include<list>
using namespace std;

#define MENU_WIDTH 200
#define MENU_HEIGHT 30
#define ITEMWIDTH 160
#define ITEMHEIGHT 30

class Container : public Window {
public:
  Container();
  Container(int x, int y, int sx, int sy);
  Container(string s, int x, int y, int sx, int sy);
  void add(Window* w);  // set next Window
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
protected:
  list<Window *>* winList;
};