#include <fstream>
#include "stdafx.h"
#include "Frame.h"
#include "MenuBar.h"
using namespace std;

#define MENU_WIDTH 200
#define MENU_HEIGHT 30

// Initialize variables
MenuBar::MenuBar() : Window(0, 0, MENU_WIDTH * 5, MENU_HEIGHT) {

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
}
