#pragma once
#include<iostream>
#include<string>
#include "Shape.h"
using namespace std;

class CLine :public Shape {
public:
  CLine(int x, int y, int sx, int sy);  // initalize variables
  void display();  // draw Line

private:
};