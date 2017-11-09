#include <fstream>
#include "stdafx.h"
#include "Frame.h"
#include "Label.h"
using namespace std;

Label::Label(string s, int x, int y, int sx, int sy) : Window(s, x, y, sx, sy) {

}

void Label::display() {
  m_frame->setPen(RGB(100, 100, 100), 1);
  m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
  m_frame->drawText(m_text, m_x + 5, m_y + 5);
}

void Label::onMouseClick(int x, int y) {
  OutputDebugString("Label\n");
}