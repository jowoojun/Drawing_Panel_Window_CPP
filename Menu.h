#pragma once
#include "Container.h"
#include<iostream>
using namespace std;

class MenuBar;
class Menu : public Container {
public :
  Menu(std::string s);  // Initialize variables
  ~Menu();  // delete menu that is inputed before
  void setMenuBar(MenuBar *); // set MenuBar
  void setNextMenu(Menu *); // set next Menu
  void setWidth(int);  // set m_xsize in Window
  void setX(int);  // set m_x in Window
  void setHeight(int);  // set m_ysize in Window.
  void display(Frame *f);  // draw Menu
  Menu* isInside(int x, int y);
  virtual void onMouseReleased(int x, int y);  // When mouse is released, it makes string output
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
private:
  MenuBar *m_menu_bar; // MenuBar
  Menu *m_next_menu;  // next Menu
  int m_width;  // menu width
};