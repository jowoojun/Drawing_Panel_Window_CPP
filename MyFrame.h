#pragma once
#include "iostream"
#include"container.h"
#include"Frame.h"
using namespace std;

class Shape;
class Menu;
class MenuItem;
class MyFrame :public Frame {
public:
  MyFrame(HWND);  // initalize variables
  virtual void onInitialize();  // Make Menu and initialize them
  virtual void processEvent(Window* src);  // check Event
private:
  Menu *smenu, *cmenu;  // Menus
  MenuItem *miRect, *miEllip, *miLine, *miMove, *miBlack, *miRed, *miBlue, *miGreen; // MenuItems
};