#pragma once
#include "iostream"
#include"container.h"
using namespace std;

class MenuItem;
class MenuBar;
class Canvas;
class Frame : public Container{
public:
	Frame(HWND);
	~Frame();
protected:
	HWND myWnd;
	HDC hDC;
	HBRUSH brushWhite, brushBlack;
	HPEN penWhite, penBlack;
	HPEN thePen;
	HBRUSH theBrush;
public:
	virtual void setWnd(HWND hWnd);
	virtual void OnLButtonDown(long wParam, int x, int y);
	virtual void OnLButtonUp(long wParam, int x, int y);
	virtual void OnRButtonDown(long wParam, int x, int y);
	virtual void OnRButtonUp(long wParam, int x, int y);
	virtual void OnChar(long ch);
	void setPenColor(COLORREF color);         // �� ���� ����. �β��� 1�� �ڵ�.
	void setPen(COLORREF color, int width);   // �� ����� �β����� ����.
	void setFillColor(COLORREF color);
	void setTextColor(COLORREF color);
	void rectangle(int x, int y, int sizeX, int sizeY);
	void ellipse(int x, int y, int sizeX, int sizeY);
	void line(int x, int y, int sizeX, int sizeY);
	void drawText(std::string str, int x, int y);
	void display();
	void invalidate();  // erase all Window and redisplay Window
    void addMenuBar(MenuBar* mb);
    void addCanvas(Canvas * c);
    virtual void onInitialize();  // Make Menu and initialize them
    virtual void processEvent(Window *src) = 0;
    virtual Window * find(int x, int y);  // �� �������� isInside(x, y) �� ��� Ŭ���� ��ü�� �����͸� ��������.

protected:
    MenuBar* m_menubar; // MenuBar
    Canvas* m_canvas; // Canvas
};

