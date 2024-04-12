#pragma once
#include "wx/wx.h"
#include "DrawingPanel.h"
//#include "MainWindow.h"
class MainWindow;
class DrawingPanel :public wxPanel
{
	int gridSize = 15;
public:
	void OnPaint(wxPaintEvent&);
	DrawingPanel(MainWindow* parent);
	void SetSize(const wxSize& _size);
	~DrawingPanel();
};

