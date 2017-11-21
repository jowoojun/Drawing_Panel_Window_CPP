#pragma once
#include "Window.h"
#include<iostream>
#include<list>
using namespace std;

#define MENU_WIDTH 100
#define MENU_HEIGHT 30
#define ITEMWIDTH 100
#define ITEMHEIGHT 30

class Container : public Window {
public:
  Container();  // Initialize variables
  Container(int x, int y, int sx, int sy);  // Initialize variables
  Container(string s, int x, int y, int sx, int sy);  // Initialize variables
  void add(Window* w);  // add Window to winList
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
  virtual Window * find(int x, int y) = 0; // find Window contained in winList
protected:
  list<Window *>* winList;  // each Window(Menu, MenuBar, Frame) is contained in winList
};