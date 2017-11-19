#include "stdafx.h"
#include "Window.h"
#include <fstream>

// Initialize variables
Window::Window() :
  m_text(""), m_x(0), m_y(0), m_xsize(0), m_ysize(0) {
  
}

// Initialize variables
Window::Window(int x, int y, int sx, int sy) :  
  m_text(""), m_x(x), m_y(y), m_xsize(sx), m_ysize(sy) {
  
}

// Initialize variables
Window::Window(string s, int x, int y, int sx, int sy) :
  m_text(s), m_x(x), m_y(y), m_xsize(sx), m_ysize(sy) {
}