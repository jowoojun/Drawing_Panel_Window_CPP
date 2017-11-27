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
  void onInitialize();  // Make Menu and initialize them
  void processEvent(Window* src);  // check Event
private:
  Menu *fmenu, *emenu;  // Menus
  MenuItem *miMove, *miRect, *miEllip, *miLine, *miBlack, *miRed, *miBlue; // MenuItems
};