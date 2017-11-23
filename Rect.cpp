#include"Frame.h"
#include "Rect.h"


Rectangle::Rect(int x, int y, int sx, int sy):Shape(x, y, sx, sy) {

}

void Rect::display() {
  m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
}