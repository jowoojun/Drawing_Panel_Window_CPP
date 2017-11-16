#pragma once
#include "Window.h"
#include<iostream>
#include<list>
using namespace std;

#define MENU_WIDTH 200
#define MENU_HEIGHT 30

class Frame;
class Container : public Window {
public:
  Container();
  Container(int x, int y, int sx, int sy);
  Container(string s, int x, int y, int sx, int sy);
  ~Container();
  void drawContent(Frame* f);  // Draw text content(text)
  void setNext(Window* w);  // set next Window
  virtual void onMouseClick(int x, int y);  // When mouse is pressed, it makes string output.
  virtual void onMouseReleased(int x, int y);  // When mouse is released, it makes string output
protected:
  list<Window *>* winList;
  string m_text; // string in Window
};