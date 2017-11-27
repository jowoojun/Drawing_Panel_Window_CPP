#include "stdafx.h"
#include"Frame.h"
#include "CLine.h"

// initalize variables
CLine::CLine(int x, int y, int sx, int sy) :Shape(x, y, sx, sy) {

}

// draw Line
void CLine::display() {
  m_frame->setPen(m_color, 1);
  m_frame->line(m_x, m_y, m_xsize, m_ysize);
}