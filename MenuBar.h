#pragma once
#include "Container.h"
#include<iostream>
using namespace std;

class Frame;
class Menu;
class MenuBar : public Container {
public:
  MenuBar();  // Initialize variables
  ~MenuBar();  // delete Menus
  void add(Menu *);  // add new menu item and set position
  void display(Frame *f);  // draw MenuBar and Menus
  bool isInside(int x, int y);  // Whether there is click point (x,y) in this window or not. If it's in there, return this. If not, find m_next
  void setAllUnclicked();
  Menu* getAnyTrueMenu();
  MenuItem* find(int x, int y);
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
protected:
  int m_menu_x; // Menu's x point
};