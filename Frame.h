#pragma once
#include "iostream"
#include "MenuBar.h"
#include "Window.h"
class Frame{
public:
	Frame(HWND);
	~Frame();
protected:
	HWND myWnd;
	HDC hDC;
	HBRUSH brushWhite, brushBlack;
	HPEN penWhite, penBlack;
	// �ӽ� ����
	int count = 0;
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
	//void eraseAll();
	void invalidate();
	void onInitialize();  // Make Menu and initialize them
	Window * find(int x, int y);  // �� �������� isInside(x, y) �� ��� Ŭ���� ��ü�� �����͸� ��������.
    void registerWindow(Window * w);  // Add new Window to windows pointer array 
protected:
    Window* first_window;  // Window starting point
    MenuBar* m_menubar; // MenuBar
};

