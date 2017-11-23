#include "stdafx.h"
#include "Menu.h"
#include "MenuItem.h"
#include "MenuBar.h"
#include "Canvas.h"
#include "MyFrame.h"


MyFrame::MyFrame(HWND hDc):Frame(hDc) {
  
}

// Make Menu and initialize them
void MyFrame::onInitialize() {
  addMenuBar(new MenuBar());
  addCanvas(new Canvas());

  m_menubar->add(fmenu = new Menu("파일"));
  m_menubar->add(emenu = new Menu("편집"));


  fmenu->add(miOpen = new MenuItem("열기"));
  fmenu->add(miSave = new MenuItem("저장"));
  fmenu->add(miExit = new MenuItem("끝내기"));

  emenu->add(miCopy = new MenuItem("복사"));
  emenu->add(miCut = new MenuItem("자르기"));
  emenu->add(miPaste = new MenuItem("붙이기"));
}

void MyFrame::processEvent(Window * src) {
  OutputDebugString("MenuItem ");
  if (src == miOpen) {
    OutputDebugString("무엇을 열까요?");
  }
  else if (src == miSave) {
    OutputDebugString("저장할까요??");
  }
  else if (src == miExit) {
    OutputDebugString("종료!");
    exit(1);
  }
  else if (src == miCopy) {
    OutputDebugString("복사합니다.");
  }
  else if (src == miCut) {
    OutputDebugString("어떤 도형을 자를까요?");
  }
  else if (src == miPaste) {
    OutputDebugString("붙여넣습니다!");
  }
  OutputDebugString(" Clicked.\n");
}
