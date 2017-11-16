#include <fstream>
#include "stdafx.h"
#include "Frame.h"
#include "Menu.h"
#include "MenuBar.h"
using namespace std;

// Initialize variables
MenuBar::MenuBar() : Container(0, 0, MENU_WIDTH * 10, MENU_HEIGHT) {
  
}

// delete Menus
MenuBar::~MenuBar() {
  delete first_menu;
}

// add new menu item and set position
void MenuBar::add(Menu *m) {
  m->setMenuBar(this);

  m->setNextMenu(first_menu);
  first_menu = m;

  m->setX(m_menu_x);
  m_menu_x += MENU_WIDTH;
  m->setWidth(MENU_WIDTH);
  m->setHeight(MENU_HEIGHT);
}

// draw MenuBar and Menus
void MenuBar::display(Frame *f) {
  f->setPen(RGB(100, 100, 100), 1);
  f->rectangle(m_x, m_y, m_xsize, m_ysize);
  drawContent(f);

  first_menu->display(f);
}

// Whether there is click point (x,y) in this window or not
// If it's in there, return true. If not, return false
bool MenuBar::isInside(int x, int y) {
  return (m_x <= x && x < m_x + m_xsize && m_y <= y && y < m_y + m_ysize);
}

// find clicked menu, if there is no, return 0
Menu* MenuBar::find(int x, int y) {
  return first_menu->isInside(x, y);
}

// When mouse is released, it makes string output
void MenuBar::onMouseReleased(int x, int y) {
  OutputDebugString("MenuBar Clicked. ");
}

// When mouse is pressed, it makes string output.
void MenuBar::onMouseClick(int x, int y) {

}
