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
  void setSize(int x, int y, int xsize, int ysize); // set size of Menu
  void display();  // draw Menu
  void drawMenuItem(); // draw MenuItems
  void add(MenuItem *mi);  // add new MenuItem in winList and set position
  void setUnclicked();  // set this Menu's m_menuClicked to be false
  Menu* getTrueMenu();  // if m_menuClicked is true, return this, if not return (Menu*) 0
  virtual Window *find(int x, int y); // find to be clicked MenuItem
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
private:
  int m_menu_Y; // menuItem height;
  bool m_menuClicked; // whether Menu is clicked or not
};