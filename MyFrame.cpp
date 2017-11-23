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

  m_menubar->add(fmenu = new Menu("����"));
  m_menubar->add(emenu = new Menu("����"));


  fmenu->add(miOpen = new MenuItem("����"));
  fmenu->add(miSave = new MenuItem("����"));
  fmenu->add(miExit = new MenuItem("������"));

  emenu->add(miCopy = new MenuItem("����"));
  emenu->add(miCut = new MenuItem("�ڸ���"));
  emenu->add(miPaste = new MenuItem("���̱�"));
}

void MyFrame::processEvent(Window * src) {
  OutputDebugString("MenuItem ");
  if (src == miOpen) {
    OutputDebugString("������ �����?");
  }
  else if (src == miSave) {
    OutputDebugString("�����ұ��??");
  }
  else if (src == miExit) {
    OutputDebugString("����!");
    exit(1);
  }
  else if (src == miCopy) {
    OutputDebugString("�����մϴ�.");
  }
  else if (src == miCut) {
    OutputDebugString("� ������ �ڸ����?");
  }
  else if (src == miPaste) {
    OutputDebugString("�ٿ��ֽ��ϴ�!");
  }
  OutputDebugString(" Clicked.\n");
}
