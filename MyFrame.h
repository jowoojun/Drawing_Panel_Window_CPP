#pragma once
#include "iostream"
#include"container.h"
#include"Frame.h"
using namespace std;

class Shape;
class Menu;
class MenuItem;
class MyFrame :public Frame {
public:
  MyFrame(HWND);
  void onInitialize();
  void processEvent(Window* src);
private:
  Menu *fmenu, *emenu;
  MenuItem *miOpen, *miSave, *miExit, *miCopy, *miCut, *miPaste;
};