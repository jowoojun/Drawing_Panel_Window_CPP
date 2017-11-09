#pragma once
#include<iostream>
#include "MenuBar.h"
#include "Window.h"

class MenuBar;
class Menu: public Window{
public :
  Menu(std::string s);  // Initialize variables
  virtual void onMouseReleased(int x, int y);  // When mouse is released, it makes string output
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
  void setMenuBar(MenuBar *); // set MenuBar
  void setNextMenu(Menu *); // set next Menu
  void setWidth(int);  // set m_xsize in Window
  void setX(int);  // set m_x in Window
  void setHeight(int);  // set m_ysize in Window
private:
  MenuBar *m_menu_bar; // MenuBar
  Menu *m_next_menu;  // next Menu
  int m_width;  // menu width
};