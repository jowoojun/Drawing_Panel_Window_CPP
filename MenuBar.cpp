#include <fstream>
#include "stdafx.h"
#include "Frame.h"
#include "MenuBar.h"
using namespace std;

// Initialize variables
MenuBar::MenuBar() : Window(0, 0, 10000, 30) {

}

// When mouse is clicked, it makes output that is string.
void MenuBar::onMouseReleased(int x, int y) {
  OutputDebugString("MenuBar Clicked. ");
}

void MenuBar::onMouseClick(int x, int y) {

}
