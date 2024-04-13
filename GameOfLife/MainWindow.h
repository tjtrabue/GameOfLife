#pragma once
#include "wx/wx.h"
//#include "DrawingPanel.h"
#include "MainWindow.h"
class DrawingPanel;
class MainWindow : public wxFrame
{
	DrawingPanel* panel = nullptr; // all variables in header files need to be intialize 
	wxBoxSizer* boxSizer = nullptr;
public:
	
	MainWindow();
	~MainWindow();
	void OnSizeChange(wxSizeEvent&);
	void GridInitialize();
	std::vector<std::vector<bool>> gridstates;
	int GridSize = 15;
};

