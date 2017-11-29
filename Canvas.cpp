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

// if you click the shape when you press the CTRL key, the clicked shape is removed.
void Canvas::deleteShape(int x, int y) {
  Shape* temp = (Shape*) 0;
  list<Shape *>::reverse_iterator i;
  for (i = shapeList->rbegin(); i != shapeList->rend(); i++) {
    if (((Shape *)*i)->isInside(x, y)) {
      temp = (*i);
      break;
    }
  }
  if (temp) {
    shapeList->remove(temp);
    delete temp;
  }
  else {
    return ;
  }}

// find Shape at clicked point
Shape* Canvas::find(int x, int y) {
  list<Shape *>::reverse_iterator i;
  for (i = shapeList->rbegin(); i != shapeList->rend(); i++) {
    if (((Shape *)*i)->isInside(x, y)) {
      return (*i);
    }
  }
  return (Shape*)0;
}

// When mouse is pressed, store starting point
void Canvas::onMouseClick(int x, int y) {
  m_startX = x;
  m_startY = y;
  clicked = true;
}

// When mouse is pressed, store ending point and make instance.
void Canvas::onMouseReleased(int x, int y) {
  if (clicked == true) {
    m_width = x - m_startX;
    m_height = y - m_startY;

    Shape* m_shape = (Shape*)0;
    switch (m_shapeType) {
      case 0:
        m_shape = new CRectangle(m_startX, m_startY, m_width, m_height);
        add(m_shape);
        break;
      case 1:
        m_shape = new CEllipse(m_startX, m_startY, m_width, m_height);
        add(m_shape);
        break;
      case 2:
        m_shape = new CLine(m_startX, m_startY, m_width, m_height);
        add(m_shape);
        break;
      case 3:
        Shape *temp;
        if (temp = (find(m_startX, m_startY))) {
          temp->moveto(m_width, m_height);
        }
        break;
    }

    m_frame->invalidate();
    clicked = false;
  }
}