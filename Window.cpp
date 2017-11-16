#include "stdafx.h"
#include "Window.h"
#include <fstream>

// Initialize variables
Window::Window() :
  m_x(0), m_y(0), m_xsize(0), m_ysize(0) {

}

// Initialize variables
Window::Window(int x, int y, int sx, int sy) :
	m_x(x), m_y(y), m_xsize(sx), m_ysize(sy) {

}