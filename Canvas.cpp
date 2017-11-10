#include <fstream>
#include "stdafx.h"
#include "string"
#include "Frame.h"
#include "Canvas.h"
using namespace std;

// Initialize variables
Canvas::Canvas(Frame *f) :Window(0, MENU_HEIGHT, 10000, 10000) {
  this->m_frame = f;
  m_frame->registerWindow(this);
}

// When mouse is released, it makes string output
void Canvas::onMouseReleased(int x, int y) {
  OutputDebugString("Canvas Clicked. (");
  OutputDebugString(to_string(x).c_str());
  OutputDebugString(", ");
  OutputDebugString(to_string(y - MENU_HEIGHT).c_str());
  OutputDebugString(")\n");
}

// When mouse is pressed, it makes string output.
void Canvas::onMouseClick(int x, int y) {

}

void Canvas::display() {

}