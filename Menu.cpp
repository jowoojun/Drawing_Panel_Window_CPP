#include "stdafx.h"
#include <fstream>
#include "Frame.h"
#include "MenuItem.h"
#include "MenuBar.h"
#include "Menu.h"
using namespace std;

// Initialize variables
Menu::Menu(std::string s) :Container(s, 0, 0, 0, 0){
  winList = new list<Window *>;
  m_menuClicked = false;
  m_menu_Y = ITEMHEIGHT;
}

// delete menu that is inputed before
Menu::~Menu() {
  signed int num = winList->size();
  for (signed int i = 0; i < num; i++) {
    Window* temp = winList->back();
    winList->pop_back();
    delete temp;
  }
}

// set size of Menu
void Menu::setSize(int x, int y, int xsize, int ysize) {
  m_x = x;
  m_y = y;
  m_xsize = xsize;
  m_ysize = ysize;
}

// draw Menu
void Menu::display(Frame *f) {
  f->setPen(RGB(100, 100, 100), 1);
  f->rectangle(m_x, m_y, m_xsize, m_ysize);
  f->drawText(m_text, m_x + 5, m_y + 5);
}

// draw MenuItems
void Menu::drawMenuItem(Frame *f) {
  list<Window *>::iterator i;
  for (i = winList->begin(); i != winList->end(); i++) {
    ((MenuItem *)*i)->display(f);
  }
}

// add new MenuItem in winList and set position
void Menu::add(MenuItem *mi) {
  Container::add(mi);
 
  mi->setSize(m_x, m_menu_Y);
  m_menu_Y += ITEMHEIGHT;
}

// set this Menu's m_menuClicked to be false
void Menu::setUnclicked() {
  m_menuClicked = false;
}

// if m_menuClicked is true, return this, if not return (Menu*) 0
Menu* Menu::getTrueMenu() {
  if (m_menuClicked == true) {
    return this;
  }
  else {
    return (Menu *)0;
  }
}

// find to be clicked MenuItem
Window* Menu::find(int x, int y) {
  list<Window *>::iterator i;
  for (i = winList->begin(); i != winList->end(); i++) {
    if ((*i)->isInside(x, y)) {
      return (*i);
    }
  }
  return (MenuItem *)0;
}

// When mouse is pressed, it makes string output.
void Menu::onMouseClick(int x, int y) {
  OutputDebugString(m_text.c_str());
  OutputDebugString(" Clicked.\n");
  m_menuClicked = true;
}