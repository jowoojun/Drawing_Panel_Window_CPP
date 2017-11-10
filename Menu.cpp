#include "stdafx.h"
#include "Frame.h"
#include "Menu.h"
using namespace std;

// Initialize variables
Menu::Menu(std::string s) :Window(s, 0, 0, 0, 0){

}

// When mouse is released, it makes string output
void Menu::onMouseReleased(int x, int y) {
  m_menu_bar->onMouseReleased(x, y);
  OutputDebugString(m_text.c_str());
  OutputDebugString(" Clicked.\n");
}

// When mouse is pressed, it makes string output.
void Menu::onMouseClick(int x, int y) {
  
}

// set MenuBar
void Menu::setMenuBar(MenuBar *mb) {
  m_menu_bar = mb;
}

// set next Menu
void Menu::setNextMenu(Menu *m) {
  m_next_menu = m;
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

void Menu::display() {
  if (m_next_menu) {
    m_next_menu->display();
  }
  m_frame->setPen(RGB(100, 100, 100), 1);
  m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
  drawContent();
}

Menu* Menu::isInside(int x, int y) {
  if (m_x <= x && x < m_x + m_xsize && m_y <= y && y < m_y + m_ysize) {
    return this;
  }
  else if (m_next_menu) {
    return m_next_menu->isInside(x, y);
  }
  else {
    return (Menu*)0;
  }
}