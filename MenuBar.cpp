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

// add new menu item and set position
void MenuBar::add(Menu *m) {
  Container::add(m);
  
  m_frame->add(this);
  m->setContainer(this);
  m->setFrame(this->m_frame);
  m->setSize(m_menu_x, 0, MENU_WIDTH, MENU_HEIGHT);
  m_menu_x += MENU_WIDTH;
}

// draw MenuBar and Menus
void MenuBar::display() {
  m_frame->setPen(RGB(100, 100, 100), 1);
  m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
  m_frame->drawText(m_text, m_x + 5, m_y + 5);

  list<Window *>::iterator i;
  for (i = winList->begin(); i != winList->end(); i++) {
    ((Menu *)*i)->display();
  }
}

// set All menu's m_menuClicked to be false
void MenuBar::setAllUnclicked() {
  list<Window *>::iterator i;
  for (i = winList->begin(); i != winList->end(); i++) {
      ((Menu *)*i)->setUnclicked();
  }
}

// find that menu's m_menuClicked is true
Menu* MenuBar::getAnyTrueMenu() {
  list<Window *>::iterator i;
  for (i = winList->begin(); i != winList->end(); i++) {
    if (((Menu *)*i)->getTrueMenu()) {
      return ((Menu *)*i);
    }
  }
  return (Menu *)0;
}

// find to be clicked menu
Window* MenuBar::find(int x, int y) {
  list<Window *>::iterator i;
  for (i = winList->begin(); i != winList->end(); i++) {
    if (((Menu *)*i)->find(x, y)) {
      return (*i);
    }
  }
  return (Window *)0;
}

// When mouse is pressed, it makes string output.
void MenuBar::onMouseClick(int x, int y) {
  OutputDebugString("MenuBar Clicked. ");
  list<Window *>::iterator i;
  for (i = winList->begin(); i != winList->end(); i++) {
    if ((*i)->isInside(x, y)) {
      ((Menu *)*i)->onMouseClick(x, y);
    }
  }
}
