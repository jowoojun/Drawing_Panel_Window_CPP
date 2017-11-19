#include "stdafx.h"
#include "MenuItem.h"
#include "Frame.h"
#include <fstream>

MenuItem::MenuItem(string s):Window(s, 0, 0, ITEMWIDTH, ITEMHEIGHT) {

}

void MenuItem::display(Frame *f) {
  f->setPen(RGB(100, 100, 100), 1);
  f->rectangle(m_x, m_y, m_xsize, m_ysize);
  f->drawText(m_text, m_x + 5, m_y + 5);
}

void MenuItem::setX(int x) {
  m_x = x;
}

void MenuItem::setY(int y) {
  m_y = y;
}

MenuItem* MenuItem::isInside(int x, int y) {
  if (m_x <= x && x < m_x + m_xsize && m_y <= y && y < m_y + m_ysize) {
    return this;
  }
  else {
    return (MenuItem *)0;
  }
}

void MenuItem::onMouseClick(int x, int y) {
  OutputDebugString(m_text.c_str());
  OutputDebugString(" Clicked.\n");
}