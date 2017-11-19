#include "stdafx.h"
#include <fstream>
#include "Frame.h"
#include "Menu.h"
#include "MenuBar.h"
using namespace std;

// Initialize variables
MenuBar::MenuBar() : Container(0, 0, MENU_WIDTH * 10, MENU_HEIGHT) {
  m_menu_x = 0;
  winList = new list<Window *>;
}

// delete Menus
MenuBar::~MenuBar() {
  signed int num = winList->size();
  for (signed int i = 0; i < num; i++) {
    Window* temp = winList->back();
    winList->pop_back();
    delete temp;
  }
}

// add new menu item and set position
void MenuBar::add(Menu *m) {
  Container::add(m);

  m->setX(m_menu_x);
  m_menu_x += MENU_WIDTH;
  m->setWidth(MENU_WIDTH);
  m->setHeight(MENU_HEIGHT);
}

// draw MenuBar and Menus
void MenuBar::display(Frame *f) {
  f->setPen(RGB(100, 100, 100), 1);
  f->rectangle(m_x, m_y, m_xsize, m_ysize);
  f->drawText(m_text, m_x + 5, m_y + 5);

  list<Window *>::iterator i;
  for (i = winList->begin(); i != winList->end(); i++) {
    ((Menu *)*i)->display(f);
  }
}

// Whether there is click point (x,y) in this window or not
// If it's in there, return true. If not, return false
bool MenuBar::isInside(int x, int y) {
  return (m_x <= x && x < m_x + m_xsize && m_y <= y && y < m_y + m_ysize);
}

void MenuBar::setAllUnclicked() {
  list<Window *>::iterator i;
  for (i = winList->begin(); i != winList->end(); i++) {
      ((Menu *)*i)->setUnclicked();
  }
}

Menu* MenuBar::getAnyTrueMenu() {
  list<Window *>::iterator i;
  for (i = winList->begin(); i != winList->end(); i++) {
    if (((Menu *)*i)->getTrueMenu()) {
      return ((Menu *)*i);
    }
  }
  return (Menu *)0;
}

MenuItem* MenuBar::find(int x, int y) {
  list<Window *>::iterator i;
  for (i = winList->begin(); i != winList->end(); i++) {
    MenuItem* temp = ((Menu *)*i)->find(x, y);
    if (temp) {
      return temp;
    }
  }
  return (MenuItem *)0;
}

// When mouse is pressed, it makes string output.
void MenuBar::onMouseClick(int x, int y) {
  OutputDebugString("MenuBar Clicked. ");
  list<Window *>::iterator i;
  for (i = winList->begin(); i != winList->end(); i++) {
    if (((Menu *)*i)->isInside(x, y)) {
      ((Menu *)*i)->onMouseClick(x, y);
    }
  }
}
