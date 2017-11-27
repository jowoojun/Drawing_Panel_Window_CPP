#include "stdafx.h"
#include"Frame.h"
#include "CEllipse.h"

// initalize variables
CEllipse::CEllipse(int x, int y, int sx, int sy) :Shape(x, y, sx, sy) {

}

// draw Ellipse
void CEllipse::display() {
  m_frame->setPen(m_color, 1);
  m_frame->ellipse(m_x, m_y, m_xsize, m_ysize);
}