#include <fstream>
#include "stdafx.h"
#include "Frame.h"
#include "Menu.h"
#include"container.h"

Container::Container():Window() {
  m_text = "";
  winList = new list<Window *>;
}

Container::Container(int x, int y, int sx, int sy) :
  Window(x, y, sx, sy){
  m_text = "";
}

Container::Container(string s, int x, int y, int sx, int sy): 
  Window(x, y, sx, sy) {
  m_text = s;
}

// remove Window until m_next is null
Container::~Container() {
  list<Window *>::iterator i;
  while(!winList->empty()){
    Window* temp = winList->back();
    winList->pop_back();
    delete(temp);
  }
}

// Draw text content(text)
void Container::drawContent(Frame* f) {
  f->drawText(m_text, m_x + 5, m_y + 5);
}

// set next Window
void Container::setNext(Window* w) {
  winList->push_back(w);
}

// When mouse is clicked, it makes output that is string.
void Container::onMouseClick(int x, int y) {
  //logger << "Window clicked, ";
  //logger << "Name: " << m_text << endl;
  OutputDebugString(m_text.c_str());
  OutputDebugString(" Clicked \n");
}

// When mouse is released, it makes string output
void Container::onMouseReleased(int x, int y) {

}



