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

	//We pass in the panel instance of DrawingPanel
	this->GridInitialize(panel);
}

void MainWindow::OnSizeChange(wxSizeEvent& event)
{
	wxSize mySize = this->GetClientSize();
	panel->SetSize(mySize);
	event.Skip();
}

//grid initialize
void MainWindow::GridInitialize(DrawingPanel *)
{
	//set the the grid size to the variable Grid size.
	gridstates.resize(GridSize);

	//Populate with default values.
	for (int i = 0; i < GridSize; i++)
	{
		gridstates[i].resize(GridSize);
		for (int j = 0; j < GridSize; j++)
			gridstates[i][j] = false;
	}

	panel->SetGridSize(GridSize);
}

MainWindow::~MainWindow()
{

}