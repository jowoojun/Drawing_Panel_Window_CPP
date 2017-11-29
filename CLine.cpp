#include "stdafx.h"
#include "Frame.h"
#include "CLine.h"

// initalize variables
CLine::CLine(int x, int y, int w, int h) :Shape(x, y, w, h) {

}

// draw Line
void CLine::display() {
  m_frame->setPen(m_color, 1);
  m_frame->line(m_startX, m_startY, m_width, m_height);
}

// Whether there is click point (x,y) in this Window or not. If it's in there, return true. If not, return false
bool CLine::isInside(int x, int y) {
  if (m_startX <= x && x < m_startX + m_width && m_startY <= y && y < m_startY + m_height) {
    return true;
  }
  else if ((m_width < 0) && (m_height < 0)) {
    if (m_startX + m_width <= x && x < m_startX  && m_startY + m_height <= y  && y < m_startY) {
      return true;
    }
  }
  else if (m_width < 0) {
    if (m_startX + m_width <= x && x < m_startX && m_startY <= y && y < m_startY + m_height) {
      return true;
    }
  }
  else if (m_height < 0) {
    if (m_startX <= x && x < m_startX + m_width && m_startY + m_height <= y && y < m_startY) {
      return true;
    }
  }
  return false;
}