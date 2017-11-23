#include <fstream>
#include "stdafx.h"
#include "string"
#include "Shape.h"
#include "Rect.h"
#include "Frame.h"
#include "Canvas.h"
using namespace std;

// Initialize variables
Canvas::Canvas(): Window(0, MENU_HEIGHT, 10000, 10000) {
  shapeList = new list<Shape *>;
}

void Canvas::display() {
  list<Shape *>::iterator i;
  for (i = shapeList->begin(); i != shapeList->end(); i++) {
    ((Shape *)*i)->display();
  }
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
    
    Rect* Rec = new Rect(pointX, pointY, releaseX, releaseY);

    shapeList;
    m_frame->line(pointX, pointY, releaseX, releaseY);
    clicked = false;
  }
}

