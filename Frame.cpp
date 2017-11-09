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
	 // *** 모든 윈도을 delete합니다.
	for (int i = 0; i < numWidget; i++) {
		delete windows[i];
	}
}

void Frame::OnLButtonDown(long wParam, int x, int y){
	OutputDebugString("Click\n");
	// 윈도을 찾아서 윈도의 onMouseClick을 실행
	Window *w = find(x, y);
	if (w) {
		w->onMouseClick(x, y);
	}
	/* 
	control key나 shift key등에 따라 다르게 하려면
	if (wParam & MK_CONTROL)  .. MK_SHIFT 등

	*/
	// 위 코드는 테스트용이고, Frame 객체의 OnLButtonDown 함수를 호출해
}

void Frame::OnLButtonUp(long wParam, int x, int y){
	/*
	 * 아래는 선 색깔, 채움 색깔을 결정하는 방법을 알려줍니다.
	setPenColor(RGB(255, 0, 0));
	setFillColor(RGB(255, 255, 0));
	rectangle(x, y, 100, 200);
	*/
}

void Frame::OnRButtonDown(long wParam, int x, int y){
	// 프로그램 종료 방법을 데모하기 위해 우측 버튼 클릭시 아래 줄을 호출하게 만들었습니다.
	PostMessage(myWnd, WM_CLOSE, NULL, NULL);
}

void Frame::OnRButtonUp(long wParam, int x, int y){
	// 
}

void Frame::OnChar(long ch){
	// 키보드 입력이 되면 이 함수가 자동 호출됩니다.  cin이나 getchar, scanf 같은
	// 표준 입력함수는 작동하지 않으니 onchar 를 잘 이용해야 합니다.
	/*
	string s;
	s = "입력된 문자: ";
	s += ch;
	setTextColor(RGB(200, 100, 100));
	drawText(s, 100, 100);
	*/
	OutputDebugString("Key 입력.\n");

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

// 모든 윈도들을 다시 그려주는 함수.  수정이 필요할 것이다.
void Frame::display(){
	// *** 모든 윈도에 대해 display를 실행해줍니다.
	for (int i = 0; i < numWidget; i++) {
		windows[i]->display();
	}
}

// 화면이 현재 제대로 안되어 있다고 알리는 함수입니다.
// 이 함수를 호출하면 화면이 지워지고 
// Main.cpp 쪽에 case WM_PAINT: 부분이 실행됩니다.
// 결국은 Frame 객체의 display가 실행되겠죠.
void Frame::invalidate(){
	InvalidateRect(myWnd, NULL, true);
}

// 모든 윈도들을 onInitialize 함수에서 초기화하자.
void Frame::onInitialize(){
	// *** 모든 윈도들을 여기에서 초기화하자.
	registerWindow(new Window("apple1",100, 50, 80, 30));
	registerWindow(new Window("kiwi", 100, 100, 80, 30 ));
	registerWindow(new Window("banana", 100, 150, 80, 30 ));
    registerWindow(new Button("Button1", 100, 200, 80, 30));
    registerWindow(new Label("Label1", 100, 250, 80, 30));
}



void Frame::registerWindow(Window * w){
	 // *** 포인터 배열에 더해주고, 윈도에도 이 Frame 객체의 포인터를 저장해주자.
	windows[numWidget++] = w;
	w->setFrame(this);
}


Window * Frame::find(int x, int y) {
	 // 각 윈도에게 isInside(x, y) 를 물어서 클릭된 객체의 포인터를 돌려주자.
	 for (int i = 0; i < this->numWidget; i++) {
	 if (windows[i]->isInside(x, y))
	 return windows[i];
	 }
	 return (Window *)NULL;
}




