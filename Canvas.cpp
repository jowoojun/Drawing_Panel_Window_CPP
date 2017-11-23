#include <fstream>
#include "stdafx.h"
#include "string"
#include "Frame.h"
#include "Canvas.h"
using namespace std;

// Initialize variables
Canvas::Canvas(): Window(0, MENU_HEIGHT, 10000, 10000) {

}

// When mouse is pressed, it makes string output.
void Canvas::onMouseClick(int x, int y) {
  OutputDebugString("Canvas: ");
  OutputDebugString(to_string(x).c_str());
  OutputDebugString(", ");
  OutputDebugString(to_string(y - MENU_HEIGHT).c_str());
  pointX = x;
  pointY = y;
  clicked = true;
}

void Canvas::onMouseReleased(int x, int y) {
  if (clicked == true){
    OutputDebugString(" --> ");
    OutputDebugString(to_string(x).c_str());
    OutputDebugString(", ");
    OutputDebugString(to_string(y - MENU_HEIGHT).c_str());
    OutputDebugString("\n");
    releaseX = x - pointX;
    releaseY = y - pointY;
    m_frame->line(pointX, pointY, releaseX, releaseY);
    clicked = false;
  }
}