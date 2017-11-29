#pragma once
#include<iostream>
#include<string>
#include "Shape.h"
using namespace std;

class CLine :public Shape {
public:
  CLine(int x, int y, int w, int h);  // initalize variables
  void display();  // draw Line
  virtual bool isInside(int x, int y);  // Whether there is click point (x,y) in this Window or not. If it's in there, return true. If not, return false
private:
};