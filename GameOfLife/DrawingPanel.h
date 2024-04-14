#pragma once
#include "wx/wx.h"
#include "DrawingPanel.h"
//#include "MainWindow.h"
class MainWindow;
class DrawingPanel :public wxPanel
{
	int gridSize = 15;
public:
	std::vector<std::vector<bool>>& gameGrid;
	void OnPaint(wxPaintEvent&);
	DrawingPanel(MainWindow* parent, std::vector<std::vector<bool>>& gameGrid);
	void OnMouseUp(wxMouseEvent& mouseEvent);
	void SetSize(const wxSize& _size);
	void SetGridSize(int newsize);
	~DrawingPanel();
	wxDECLARE_EVENT_TABLE();
};

