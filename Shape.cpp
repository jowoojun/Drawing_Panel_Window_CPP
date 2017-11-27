#include "stdafx.h"
#include "Canvas.h"
#include "Frame.h"
#include "Shape.h"
#include <fstream>

// initalize variables
Shape::Shape(int x, int y, int sx, int sy) :m_x(x),  m_y(y), m_xsize(sx), m_ysize(sy){

}

// remove Shape
Shape::~Shape() {

}
// set Frame
void Shape::setFrame(Frame *f) {
  m_frame = f;
}

// set Color
void Shape::setColor(COLORREF color) {
  m_color = color;
}

bool Shape::isinside(int x, int y) {
  return (m_x <= x && x < m_x + m_xsize && m_y <= y && y < m_y + m_ysize);
}

// move shape
void Shape::moveto(int sx, int sy) {
  m_x += sx;
  m_y += sy;
}