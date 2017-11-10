#include "stdafx.h"
#include "stdio.h"
#include "string"
#include "Window.h"
#include "Menu.h"
#include "Frame.h"
using namespace std;

Frame::Frame(HWND w):myWnd(w){
	hDC = ::GetDC(w);

	onInitialize();
}

void Frame::setWnd(HWND hWnd) {

}

Frame::~Frame(){
	 // *** ��� ������ delete�մϴ�.
    delete first_window;
}

void Frame::OnLButtonDown(long wParam, int x, int y){
	OutputDebugString("Click\n");
    Window *w = find(x, y);
    if (w) {
      w->onMouseClick(x, y);
    }
	/* 
	control key�� shift key� ���� �ٸ��� �Ϸ���
	if (wParam & MK_CONTROL)  .. MK_SHIFT ��

	*/
}

void Frame::OnLButtonUp(long wParam, int x, int y){
    Window *w = find(x, y);
    if (w) {
      w->onMouseReleased(x, y);
    }
    else {
      OutputDebugString("Click ");
    }
	/*
	 * �Ʒ��� �� ����, ä�� ������ �����ϴ� ����� �˷��ݴϴ�.
	setPenColor(RGB(255, 0, 0));
	setFillColor(RGB(255, 255, 0));
	rectangle(x, y, 100, 200);
	*/
}

void Frame::OnRButtonDown(long wParam, int x, int y){
	// ���α׷� ���� ����� �����ϱ� ���� ���� ��ư Ŭ���� �Ʒ� ���� ȣ���ϰ� ��������ϴ�.
	PostMessage(myWnd, WM_CLOSE, NULL, NULL);
}

void Frame::OnRButtonUp(long wParam, int x, int y){
	// 
}

void Frame::OnChar(long ch){
	// Ű���� �Է��� �Ǹ� �� �Լ��� �ڵ� ȣ��˴ϴ�.  cin�̳� getchar, scanf ����
	// ǥ�� �Է��Լ��� �۵����� ������ onchar �� �� �̿��ؾ� �մϴ�.
	/*
	string s;
	s = "�Էµ� ����: ";
	s += ch;
	setTextColor(RGB(200, 100, 100));
	drawText(s, 100, 100);
	*/
	OutputDebugString("Key �Է�.\n");
}

void Frame::setPenColor(COLORREF color){
	thePen = CreatePen(PS_SOLID, 1, color);
	SelectObject(hDC, thePen);
}

void Frame::setPen(COLORREF color, int width){
	thePen = CreatePen(PS_SOLID, width, color);
	SelectObject(hDC, thePen);
}

void Frame::setFillColor(COLORREF color){
	theBrush = CreateSolidBrush(color);
	SelectObject(hDC, theBrush);
}

void Frame::setTextColor(COLORREF color){
	SetTextColor(hDC, color);
}

void Frame::rectangle(int x, int y, int sizeX, int sizeY){
	Rectangle(hDC, x, y, x + sizeX, y + sizeY);
}

void Frame::ellipse(int x, int y, int sizeX, int sizeY){
	Ellipse(hDC, x, y, x + sizeX, y + sizeY);
}

void Frame::line(int x, int y, int sizeX, int sizeY){
	MoveToEx(hDC, x, y, NULL);
	LineTo(hDC, x + sizeX, y + sizeY);
}


void Frame::drawText(std::string str, int x, int y){
	TextOut(hDC, x, y, str.c_str(), strlen(str.c_str()));
}

// Redraw every window
void Frame::display(){
    m_menubar->display();
    //canverse->display();
}

// ȭ���� ���� ����� �ȵǾ� �ִٰ� �˸��� �Լ��Դϴ�.
// �� �Լ��� ȣ���ϸ� ȭ���� �������� 
// Main.cpp �ʿ� case WM_PAINT: �κ��� ����˴ϴ�.
// �ᱹ�� Frame ��ü�� display�� ����ǰ���.
void Frame::invalidate(){
	InvalidateRect(myWnd, NULL, true);
}

// Make Menu and initialize them
void Frame::onInitialize(){
    m_menubar = new MenuBar(this);
    Menu *fmenu = new Menu("����");
    Menu *emenu = new Menu("����");
    m_menubar->add(fmenu);
    m_menubar->add(emenu);
    m_canvas = new Canvas(this);
}

// Add new Window to windows pointer array 
void Frame::registerWindow(Window * w){
    w->setNext(first_window);
    first_window = w;
}

// �� �������� isInside(x, y) �� ��� Ŭ���� ��ü�� �����͸� ��������.
Window * Frame::find(int x, int y) {
  if (m_menubar->isInside(x, y)) {
    Window* temp = m_menubar->find(x, y);
    if (temp) {
      return temp;
    }
    else {
      return m_menubar;
    }
  }
  else {
    return m_canvas;//return canverse;
  }
}