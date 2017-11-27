#include "stdafx.h"
#include"Frame.h"
#include "CRectangle.h"

// initalize variables
CRectangle::CRectangle(int x, int y, int sx, int sy):Shape(x, y, sx, sy) {

}

// draw Rectangle
void CRectangle::display() {
  m_frame->setPen(m_color, 1);
  m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
}