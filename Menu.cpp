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
  m_menu_Y = ITEMHEIGHT;
  m_menuClicked = false;
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

// set m_xsize in Window
void Menu::setWidth(int width) {
  this->m_xsize = width;
}

// set m_x in Window
void Menu::setX(int x) {
  this->m_x = x;
}

// set m_ysize in Window
void Menu::setHeight(int height) {
  this->m_ysize = height;
}

// draw Menu
void Menu::display(Frame *f) {
  f->setPen(RGB(100, 100, 100), 1);
  f->rectangle(m_x, m_y, m_xsize, m_ysize);
  f->drawText(m_text, m_x + 5, m_y + 5);
}

bool Menu::isInside(int x, int y) {
  return (m_x <= x && x < m_x + m_xsize && m_y <= y && y < m_y + m_ysize);
}

void Menu::drawMenuItem(Frame *f) {
  list<Window *>::iterator i;
  for (i = winList->begin(); i != winList->end(); i++) {
    ((MenuItem *)*i)->display(f);
  }
}

void Menu::add(MenuItem *mi) {
  mi->setX(m_x + 20);
  mi->setY(m_menu_Y);
  m_menu_Y += ITEMHEIGHT;

  Container::add(mi);
}

void Menu::setUnclicked() {
  m_menuClicked = false;
}

Menu* Menu::getTrueMenu() {
  if (m_menuClicked == true) {
    return this;
  }
  else {
    return (Menu *)0;
  }
}

MenuItem* Menu::find(int x, int y) {
  list<Window *>::iterator i;
  for (i = winList->begin(); i != winList->end(); i++) {
    MenuItem* temp = ((MenuItem*)*i)->isInside(x, y);
    if (temp) {
      return temp;
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