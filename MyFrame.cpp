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

  m_menubar->add(smenu = new Menu("도형"));
  m_menubar->add(cmenu = new Menu("색"));


  smenu->add(miRect = new MenuItem("사각형"));
  smenu->add(miEllip = new MenuItem("타원"));
  smenu->add(miLine = new MenuItem("선분"));
  smenu->add(miMove = new MenuItem("이동"));

  cmenu->add(miBlack = new MenuItem("검은색"));
  cmenu->add(miRed = new MenuItem("빨간색"));
  cmenu->add(miBlue = new MenuItem("파란색"));
  cmenu->add(miGreen = new MenuItem("초록색"));
}

// check Event
void MyFrame::processEvent(Window * src) {
  OutputDebugString("MenuItem ");
  if (src == miMove) {
    m_canvas->setShapeType(3);
  }
  else if (src == miRect) {
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
  else if (src == miGreen) {
    m_canvas->setColor(RGB(0, 255, 0));
  }
  OutputDebugString(" Clicked.\n");
}
