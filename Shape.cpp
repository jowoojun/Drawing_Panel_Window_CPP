#include "stdafx.h"
#include "Canvas.h"
#include "Frame.h"
#include "Shape.h"

// initalize variables
Shape::Shape(int x, int y, int sx, int sy) :m_x(x),  m_y(y), m_xsize(sx), m_ysize(sy){

}

// set Frame
void Shape::setFrame(Frame *f) {
  m_frame = f;
}

// set Color
void Shape::setColor(COLORREF color) {
  m_color = color;
}