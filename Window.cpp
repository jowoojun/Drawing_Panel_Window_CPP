#include "stdafx.h"
#include "Frame.h"
#include "Window.h"
#include <fstream>

// Initialize variables
Window::Window(int x, int y, int sx, int sy) :
	m_x(x), m_y(y), m_xsize(sx), m_ysize(sy), m_text(""),m_next(0) {

}

// Initialize variables
Window::Window(string s, int x, int y, int sx, int sy)
	: Window(x, y, sx, sy){
	m_text = s;
}

// remove Window until m_next is null
Window::~Window() {
    if (m_next)
      delete m_next;
}

// Set m_frame to parameter
void Window::setFrame(Frame *v) {
	m_frame = v;
}

// Draw Window frame(Rectangle)
void Window::display() {
    m_frame->setPen(RGB(100, 100, 100), 1);
    m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
    drawContent();
}

// Draw text content(text)
void Window::drawContent() {
	m_frame->drawText(m_text, m_x + 5, m_y + 5);
}

// When mouse is clicked, it makes output that is string.
void Window::onMouseClick(int x, int y) {
	//logger << "Window clicked, ";
	//logger << "Name: " << m_text << endl;
	OutputDebugString(m_text.c_str());
	OutputDebugString(" Clicked \n");
}

// Whether there is click point (x,y) in this window or not
// If it's in there, return true. If not, return false
bool Window::isInside(int x, int y) {
  return (m_x <= x && x < m_x + m_xsize && m_y <= y && y < m_y + m_ysize);
}

// set next Window
void Window::setNext(Window* w) {
    m_next = w;
}
