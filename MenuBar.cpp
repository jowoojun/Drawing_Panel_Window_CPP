#include <fstream>
#include "stdafx.h"
#include "Frame.h"
#include "MenuBar.h"
using namespace std;



// Initialize variables
MenuBar::MenuBar(Frame* f) : Window(0, 0, MENU_WIDTH * 10, MENU_HEIGHT) {
  this->m_frame = f;
  m_frame->registerWindow(this);
}

// When mouse is released, it makes string output
void MenuBar::onMouseReleased(int x, int y) {
  OutputDebugString("MenuBar Clicked. ");
}

// When mouse is pressed, it makes string output.
void MenuBar::onMouseClick(int x, int y) {

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

  m_frame->registerWindow(m);
  m->setFrame(m_frame);
}

void MenuBar::display() {
  m_frame->setPen(RGB(100, 100, 100), 1);
  m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
  drawContent();

  first_menu->display();
}

Menu* MenuBar::find(int x, int y) {
  return first_menu->isInside(x, y);
}