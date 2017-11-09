#pragma once
#include "Window.h"
#include "Menu.h"
#include<iostream>

class Menu;
class MenuBar : public Window {
public:
  MenuBar();  // Initialize variables
  virtual void onMouseReleased(int x, int y);  // When mouse is released, it makes string output
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
  void add(Menu *);  // add new menu item and set position
private:
  Menu *first_menu;  // Menu starting point
  int m_menu_x = 0; // Menu's x point
};