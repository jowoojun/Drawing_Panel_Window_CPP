#include <fstream>
#include "stdafx.h"
#include "Frame.h"
#include "Button.h"
using namespace std;

Button::Button(string s, int x, int y, int sx, int sy) : Window(s, x, y, sx, sy) {

}

void Button::display() {
  m_frame->setPen(RGB(100, 100, 100), 1);
  m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
  string str = m_text +" :" +to_string(m_count);
  m_frame->drawText(str, m_x + 5, m_y + 5);
}

void Button::onMouseClick(int x,int y) {
  OutputDebugString("¹öÆ°\n");
  m_count++;
  display();
}