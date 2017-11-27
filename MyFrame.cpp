#include "stdafx.h"
#include "Menu.h"
#include "MenuItem.h"
#include "MenuBar.h"
#include "Canvas.h"
#include "MyFrame.h"

// initalize variables
MyFrame::MyFrame(HWND hDc):Frame(hDc) {
  
}

// Make Menu and initialize them
void MyFrame::onInitialize() {
  addMenuBar(new MenuBar());
  addCanvas(new Canvas());

  m_menubar->add(fmenu = new Menu("도형"));
  m_menubar->add(emenu = new Menu("색"));


  fmenu->add(miRect = new MenuItem("사각형"));
  fmenu->add(miEllip = new MenuItem("타원"));
  fmenu->add(miLine = new MenuItem("선분"));

  emenu->add(miBlack = new MenuItem("검은색"));
  emenu->add(miRed = new MenuItem("빨간색"));
  emenu->add(miBlue = new MenuItem("파란색"));
}

// check Event
void MyFrame::processEvent(Window * src) {
  OutputDebugString("MenuItem ");
  if (src == miRect) {
    m_canvas->setShapeType(0);
  }
  else if (src == miEllip) {
    m_canvas->setShapeType(1);
  }
  else if (src == miLine) {
    m_canvas->setShapeType(2);
  }
  else if (src == miBlack) {
    m_canvas->setColor(RGB(0, 0, 0));
  }
  else if (src == miRed) {
    m_canvas->setColor(RGB(255, 0, 0));
  }
  else if (src == miBlue) {
    m_canvas->setColor(RGB(0, 0, 255));
  }
  OutputDebugString(" Clicked.\n");
}
