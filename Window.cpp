#include "stdafx.h"
#include "Window.h"
#include "Frame.h"
#include <fstream>

Window::Window(int x, int y, int sx, int sy) :
	m_x(x), m_y(y), m_xsize(sx), m_ysize(sy), m_text("") {
}
Window::Window(string s, int x, int y, int sx, int sy)
	: Window(x, y, sx, sy)
{
	m_text = s;
}
void Window::setFrame(Frame *v) {
	m_frame = v;
}
void Window::display() {
	m_frame->setPen(RGB(100, 100, 100), 1);
	m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
	drawContent();
}

void Window::drawContent() {
	m_frame->drawText(m_text, m_x + 5, m_y + 5);
}
void Window::onMouseClick(int x, int y) {
	//logger << "Window clicked, ";
	//logger << "Name: " << m_text << endl;
	OutputDebugString(m_text.c_str());
	OutputDebugString(" Clicked \n");
}

bool Window::isInside(int x, int y) {
	return m_x <= x && x < m_x + m_xsize &&
		m_y <= y && y < m_y + m_ysize;
}
