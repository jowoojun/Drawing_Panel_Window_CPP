#pragma once
#include<iostream>
#include<string>
#include "Shape.h"
using namespace std;

class Rect:public Shape{
public:
  Rect(int x, int y, int sx, int sy);
  void display();

private:
};