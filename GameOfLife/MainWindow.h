#pragma once
#include "wx/wx.h"
//#include "DrawingPanel.h"
#include "MainWindow.h"
class DrawingPanel;
class MainWindow : public wxFrame
{
	DrawingPanel* panel = nullptr; // all variables in header files need to be intialize 
public:
	
	MainWindow();
	~MainWindow();
};

