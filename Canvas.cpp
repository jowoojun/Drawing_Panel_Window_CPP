#include <fstream>
#include "stdafx.h"
#include "string"
#include "Shape.h"
#include "CRectangle.h"
#include "CEllipse.h"
#include "CLine.h"
#include "Frame.h"
#include "Canvas.h"
using namespace std;

// Initialize variables
Canvas::Canvas(): Window(0, MENU_HEIGHT, 10000, 10000) {
  shapeList = new list<Shape *>;
  m_shapeType = 0;
  m_color = RGB(0, 0, 0);
}

// display all shapeList
void Canvas::display() {
  list<Shape *>::iterator i;
  for (i = shapeList->begin(); i != shapeList->end(); i++) {
    ((Shape *)*i)->display();
  }
}

// add Shape in shpaeList
void Canvas::add(Shape* s) {
  shapeList->push_back(s);
  s->setFrame(this->m_frame);
  s->setColor(m_color);
}

// set shape of Shape
void Canvas::setShapeType(int type) {
  m_shapeType = type;
}

// set color of Shape
void Canvas::setColor(COLORREF color) {
  m_color = color;
}

// When mouse is pressed, store starting point
void Canvas::onMouseClick(int x, int y) {
  OutputDebugString("Canvas: ");
  OutputDebugString(to_string(x).c_str());
  OutputDebugString(", ");
  OutputDebugString(to_string(y - MENU_HEIGHT).c_str());
  pointX = x;
  pointY = y;
  clicked = true;
}

// When mouse is pressed, store ending point and make instance.
void Canvas::onMouseReleased(int x, int y) {
  if (clicked == true) {
    OutputDebugString(" --> ");
    OutputDebugString(to_string(x).c_str());
    OutputDebugString(", ");
    OutputDebugString(to_string(y - MENU_HEIGHT).c_str());
    OutputDebugString("\n");
    releaseX = x - pointX;
    releaseY = y - pointY;

    Shape* m_shape = (Shape*)0;
    switch (m_shapeType) {
    case 0:
      m_shape = new CRectangle(pointX, pointY, releaseX, releaseY);
      break;
    case 1:
      m_shape = new CEllipse(pointX, pointY, releaseX, releaseY);
      break;
    case 2:
      m_shape = new CLine(pointX, pointY, releaseX, releaseY);
      break;
    }

    add(m_shape);
    m_frame->invalidate();
    clicked = false;
  }
}