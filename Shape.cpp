#include "stdafx.h"
#include "Canvas.h"
#include "Frame.h"
#include "Shape.h"
#include <fstream>

// initalize variables
Shape::Shape(int x, int y, int w, int h) :m_startX(x),  m_startY(y), m_width(w), m_height(h){
  
}

// set Frame
void Shape::setFrame(Frame *f) {
  m_frame = f;
}

// set Color
void Shape::setColor(COLORREF color) {
  m_color = color;
}

// move shape
void Shape::moveto(int w, int h) {
  m_startX += w;
  m_startY += h;
}

// Whether there is click point (x,y) in this Window or not. If it's in there, return true. If not, return false
bool Shape::isInside(int x, int y) {
  return (m_startX <= x && x < m_startX + m_width && m_startY <= y && y < m_startY + m_height);
}