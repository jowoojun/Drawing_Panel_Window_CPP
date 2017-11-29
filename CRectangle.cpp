#include "stdafx.h"
#include"Frame.h"
#include "CRectangle.h"

// initalize variables
CRectangle::CRectangle(int x, int y, int w, int h):Shape(x, y, w, h) {
  if ((m_width < 0) && (m_height < 0)) {
    m_startX += m_width;
    m_width *= -1;
    m_startY += m_height;
    m_height *= -1;
  }
  else if (m_width < 0) {
    m_startX += m_width;
    m_width *= -1;
  }
  else if (m_height < 0) {
    m_startY += m_height;
    m_height *= -1;
  }
}

// draw Rectangle
void CRectangle::display() {
  m_frame->setPen(m_color, 1);
  m_frame->rectangle(m_startX, m_startY, m_width, m_height);
}