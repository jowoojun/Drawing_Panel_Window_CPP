#include <fstream>
#include "stdafx.h"
#include "Frame.h"
#include "Menu.h"
#include"container.h"

Container::Container():Window() {
  winList = new list<Window *>;
}

Container::Container(int x, int y, int sx, int sy) :
  Window(x, y, sx, sy){
}

Container::Container(string s, int x, int y, int sx, int sy): 
  Window(s, x, y, sx, sy) {
}

// set next Window
void Container::add(Window* w) {
  winList->push_back(w);
}

// When mouse is clicked, it makes output that is string.
void Container::onMouseClick(int x, int y) {
  //logger << "Window clicked, ";
  //logger << "Name: " << m_text << endl;
  OutputDebugString(m_text.c_str());
  OutputDebugString(" Clicked \n");
}



