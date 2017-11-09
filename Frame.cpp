#include "stdafx.h"
#include "Frame.h"
#include "Button.h"
#include "Label.h"
#include "stdio.h"
#include "iostream"
#include "string"
#include "Window.h"
using namespace std;

Frame::Frame(HWND w):myWnd(w){
	hDC = ::GetDC(w);

	onInitialize();
}

void Frame::setWnd(HWND hWnd) {

}

Frame::~Frame(){
	 // *** ��� ������ delete�մϴ�.
	for (int i = 0; i < numWidget; i++) {
		delete windows[i];
	}
}

void Frame::OnLButtonDown(long wParam, int x, int y){
	OutputDebugString("Click\n");
	// ������ ã�Ƽ� ������ onMouseClick�� ����
	Window *w = find(x, y);
	if (w) {
		w->onMouseClick(x, y);
	}
	/* 
	control key�� shift key� ���� �ٸ��� �Ϸ���
	if (wParam & MK_CONTROL)  .. MK_SHIFT ��

	*/
	// �� �ڵ�� �׽�Ʈ���̰�, Frame ��ü�� OnLButtonDown �Լ��� ȣ����
}

void Frame::OnLButtonUp(long wParam, int x, int y){
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

// ��� �������� �ٽ� �׷��ִ� �Լ�.  ������ �ʿ��� ���̴�.
void Frame::display(){
	// *** ��� ������ ���� display�� �������ݴϴ�.
	for (int i = 0; i < numWidget; i++) {
		windows[i]->display();
	}
}

// ȭ���� ���� ����� �ȵǾ� �ִٰ� �˸��� �Լ��Դϴ�.
// �� �Լ��� ȣ���ϸ� ȭ���� �������� 
// Main.cpp �ʿ� case WM_PAINT: �κ��� ����˴ϴ�.
// �ᱹ�� Frame ��ü�� display�� ����ǰ���.
void Frame::invalidate(){
	InvalidateRect(myWnd, NULL, true);
}

// ��� �������� onInitialize �Լ����� �ʱ�ȭ����.
void Frame::onInitialize(){
	// *** ��� �������� ���⿡�� �ʱ�ȭ����.
	registerWindow(new Window("apple1",100, 50, 80, 30));
	registerWindow(new Window("kiwi", 100, 100, 80, 30 ));
	registerWindow(new Window("banana", 100, 150, 80, 30 ));
    registerWindow(new Button("Button1", 100, 200, 80, 30));
    registerWindow(new Label("Label1", 100, 250, 80, 30));
}



void Frame::registerWindow(Window * w){
	 // *** ������ �迭�� �����ְ�, �������� �� Frame ��ü�� �����͸� ����������.
	windows[numWidget++] = w;
	w->setFrame(this);
}


Window * Frame::find(int x, int y) {
	 // �� �������� isInside(x, y) �� ��� Ŭ���� ��ü�� �����͸� ��������.
	 for (int i = 0; i < this->numWidget; i++) {
	 if (windows[i]->isInside(x, y))
	 return windows[i];
	 }
	 return (Window *)NULL;
}




