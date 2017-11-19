#pragma once
#include "Container.h"
#include<iostream>
#include <list>
using namespace std;

class Frame;
class MenuItem;
class MenuBar;
class Menu : public Container {
public :
  Menu(std::string s);  // Initialize variables
  ~Menu();  // delete menu that is inputed before
  void setWidth(int);  // set m_xsize in Window
  void setX(int);  // set m_x in Window
  void setHeight(int);  // set m_ysize in Window.
  void display(Frame *f);  // draw Menu
  bool isInside(int x, int y);
  void drawMenuItem(Frame *f);
  void add(MenuItem *mi);
  void setUnclicked();
  Menu* getTrueMenu();
  MenuItem *find(int x, int y);
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
private:
  int m_menu_Y; // menuItem height;
  bool m_menuClicked;
};