#include "stdafx.h"
#include "MenuItem.h"
#include "Frame.h"
#include <fstream>

// Initialize variables
MenuItem::MenuItem(string s):Window(s, 0, 0, ITEMWIDTH, ITEMHEIGHT) {

}

// draw MenuItem
void MenuItem::display(Frame *f) {
  f->setPen(RGB(100, 100, 100), 1);
  f->rectangle(m_x, m_y, m_xsize, m_ysize);
  f->drawText(m_text, m_x + 5, m_y + 5);
}

// set X point
void MenuItem::setSize(int x, int y) {
  m_x = x;
  m_y = y;
}

// When mouse is pressed, it makes string output.
void MenuItem::onMouseClick(int x, int y) {
  OutputDebugString("MenuItem ");
  OutputDebugString(m_text.c_str());
  OutputDebugString(" Clicked.\n");
}