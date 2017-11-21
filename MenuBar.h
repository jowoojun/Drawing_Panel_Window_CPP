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
  void add(Menu *);  // add new menu in winList and set position
  void display(Frame *f);  // draw MenuBar and Menus
  void setAllUnclicked();  // set All menu's m_menuClicked to be false
  Menu* getAnyTrueMenu();  // find that menu's m_menuClicked is true
  virtual Window* find(int x, int y); // find to be clicked Menu
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
protected:
  int m_menu_x; // Menu's x point
};