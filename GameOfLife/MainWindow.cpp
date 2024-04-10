#include "MainWindow.h"
#include "DrawingPanel.h"

MainWindow::MainWindow() :wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(0, 0), wxSize(500, 300))
{
	DrawingPanel* panel = new DrawingPanel(this);
}

MainWindow::~MainWindow()
{

}