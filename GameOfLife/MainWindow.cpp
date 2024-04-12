#include "MainWindow.h"
#include "DrawingPanel.h"

MainWindow::MainWindow() :wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(0, 0), wxSize(500, 300))
{
	DrawingPanel* panel = new DrawingPanel(this);
	boxSizer = new wxBoxSizer(wxVERTICAL);
	boxSizer->Add(panel, 1, wxEXPAND | wxALL);
	this->panel = panel;
	this->SetSizer(boxSizer);

	this->Bind(wxEVT_SIZE, &MainWindow::OnSizeChange, this);
}

void MainWindow::OnSizeChange(wxSizeEvent& event)
{
	wxSize mySize = this->GetClientSize();
	panel->SetSize(mySize);
	event.Skip();
}

MainWindow::~MainWindow()
{

}