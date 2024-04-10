#pragma once
#include "wx/wx.h"
#include "DrawingPanel.h"
//#include "MainWindow.h"
class MainWindow;
class DrawingPanel :public wxPanel
{
public:
	void OnPaint(wxPaintEvent&);
	DrawingPanel(MainWindow* parent);
	~DrawingPanel();
};

