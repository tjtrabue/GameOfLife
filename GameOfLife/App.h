#pragma once
#include "MainWindow.h"
#include "wx/wx.h"

class App : public wxApp
{
private:

public:
	MainWindow* window;
	App();
	~App();
	virtual bool OnInit();
};

