#pragma once
#include "wx/wx.h"
#include "DrawingPanel.h"
#include "Settings.h"
//#include "MainWindow.h"
class MainWindow;
class DrawingPanel :public wxPanel
{
	Settings* setting;
public:
	std::vector<std::vector<bool>>& gameGrid;
	std::vector<std::vector<int>>& neighborCount;
	void OnPaint(wxPaintEvent&);
	DrawingPanel(MainWindow* parent, std::vector<std::vector<bool>>& gameGrid, std::vector<std::vector<int>>& neighborCount);
	void OnMouseUp(wxMouseEvent& mouseEvent);
	void SetSize(const wxSize& _size);
	void SetSetting(Settings*);
	void SetGridSize(int newsize);
	~DrawingPanel();
	wxDECLARE_EVENT_TABLE();
};

