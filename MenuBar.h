#pragma once
#include "Container.h"
#include<iostream>
using namespace std;

class Menu;
class MenuBar : public Container {
public:
  MenuBar();  // Initialize variables
  ~MenuBar();  // delete Menus
  void add(Menu *);  // add new menu item and set position
  void display(Frame *f);  // draw MenuBar and Menus
  bool isInside(int x, int y);  // Whether there is click point (x,y) in this window or not. If it's in there, return this. If not, find m_next
  Menu* find(int x, int y);  // find clicked menu, if there is no, return 0
  virtual void onMouseReleased(int x, int y);  // When mouse is released, it makes string output
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
protected:
  Menu *first_menu;  // Menu starting point
  int m_menu_x = 0; // Menu's x point
};