#include "MainWindow.h"
#include "DrawingPanel.h"
#include "play.xpm"
#include "pause.xpm"
#include "next.xpm"
#include "trash.xpm"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
	EVT_SIZE(MainWindow::OnSizeChange)
	EVT_MENU(MainWindow::PLAY_ID, MainWindow::OnPlay)
	EVT_MENU(MainWindow::PAUSE_ID, MainWindow::OnPause)
	EVT_MENU(MainWindow::NEXT_ID, MainWindow::OnNext)
	EVT_MENU(MainWindow::TRASH_ID, MainWindow::OnTrash)
wxEND_EVENT_TABLE()


MainWindow::MainWindow() :wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(0, 0), wxSize(500, 300))
{
	//tool bar
	toolBar = CreateToolBar();
	wxBitmap playIcon(play_xpm);
	wxBitmap pauseIcon(pause_xpm);
	wxBitmap nextIcon(next_xpm);
	wxBitmap trashIcon(trash_xpm);
	toolBar->AddTool(PLAY_ID, "Play", playIcon);
	toolBar->AddTool(PAUSE_ID, "Pause", pauseIcon);
	toolBar->AddTool(NEXT_ID, "Next", nextIcon);
	toolBar->AddTool(TRASH_ID, "Trash", trashIcon);
	toolBar->Realize();
	//status bar
	statusBar = CreateStatusBar();
	DrawingPanel* panel = new DrawingPanel(this, gridstates);
	boxSizer = new wxBoxSizer(wxVERTICAL);
	boxSizer->Add(panel, 1, wxEXPAND | wxALL);
	this->panel = panel;
	this->SetSizer(boxSizer);


	
	//this->Bind(wxEVT_SIZE, &MainWindow::OnSizeChange, this);

	this->GridInitialize();

	this->Layout();
}

void MainWindow::OnSizeChange(wxSizeEvent& event)
{
	wxSize mySize = this->GetClientSize();
	if(panel != nullptr)
	{ 
		panel->SetSize(mySize);
	}
	event.Skip();
}

void MainWindow::OnPlay(wxCommandEvent& event)
{

}

void MainWindow::OnPause(wxCommandEvent& event)
{

}

void MainWindow::OnNext(wxCommandEvent& event)
{
	NextGeneration();

}

void MainWindow::OnTrash(wxCommandEvent& event)
{
	for (auto& row : gridstates) 
		std::fill(row.begin(), row.end(), false);
	
	SetStatusBarText(wxString("Generations:0   Living Cells:0"));
	livingCells = 0;
	panel->Refresh();
}



int MainWindow::NeighborCount(int x, int y)
{
	int result = 0;

	// this does 8*4 = 32 comparisons
	if (0 <= x - 1 && x - 1 < GridSize && 0 <= y && y < GridSize)
		if (gridstates[x - 1][y]) ++result;
	if (0 <= x - 1 && x - 1 < GridSize && 0 <= y - 1 && y - 1 < GridSize)
		if (gridstates[x - 1][y - 1]) ++result;
	if (0 <= x && x < GridSize && 0 <= y - 1 && y - 1 < GridSize)
		if (gridstates[x][y - 1]) ++result;
	if (0 <= x + 1 && x + 1 < GridSize && 0 <= y - 1 && y - 1 < GridSize)
		if (gridstates[x + 1][y - 1]) ++result;
	if (0 <= x + 1 && x + 1 < GridSize && 0 <= y && y < GridSize)
		if (gridstates[x + 1][y]) ++result;
	if (0 <= x + 1 && x + 1 < GridSize && 0 <= y + 1 && y + 1 < GridSize)
		if (gridstates[x + 1][y + 1]) ++result;
	if (0 <= x && x < GridSize && 0 <= y + 1 && y + 1 < GridSize)
		if (gridstates[x][y + 1]) ++result;
	if (0 <= x - 1 && x - 1 < GridSize && 0 <= y + 1 && y + 1 < GridSize)
		if (gridstates[x - 1][y + 1]) ++result;

	return result;

}
 void MainWindow::NextGeneration()
{
	// this initializes a GridSize vector of GridSize vectors of boolean falses
	/*std::vector<std::vector<bool>> sandbox = gridstates;
	int number_alive = 0;

	for (int i = 0; i < GridSize; i++) {
		for (int j = 0; j < GridSize; j++) {
			int n = NeighborCount(i, j);
			if (gridstates[i][j]) { //alive
				if (2 <= n && n <= 3) {
					sandbox[i][j] = true; // live cell with 2-3 live neighbors
					number_alive++;
				}
			}
			else { // dead
				if (n == 3) {
					sandbox[i][j] = true; // dead cell with exactly 3 live neighbors
					number_alive++;
				}
			}
		}
	}
	swap(gridstates, sandbox);
	livingCells = number_alive;
	generation++;
	std::string statusText = "Generation: " + std::to_string(generation) + ", Living Cells: " + std::to_string(number_alive);
	SetStatusBarText(wxString(statusText));
	panel->Refresh();*/
	 std::vector<std::vector<bool>> sandbox(GridSize, std::vector<bool>(GridSize, false));
	 int number_alive = 0;

	 for (int i = 0; i < GridSize; i++) {
		 for (int j = 0; j < GridSize; j++) {
			 int n = NeighborCount(i, j);
			 if (gridstates[i][j]) { // Alive
				 if (n < 2 || n > 3) {
					 sandbox[i][j] = false; // Cell dies
				 }
				 else {
					 sandbox[i][j] = true; // Cell remains alive
					 number_alive++;
				 }
			 }
			 else { // Dead
				 if (n == 3) {
					 sandbox[i][j] = true; // Cell becomes alive
					 number_alive++;
				 }
			 }
		 }
	 }

	 swap(gridstates, sandbox); // Update the grid to the next generation
	 livingCells = number_alive; // Update the count of living cells
	 generation++; // Increment generation count
	 std::string statusText = "Generation: " + std::to_string(generation) + ", Living Cells: " + std::to_string(number_alive);
	 SetStatusBarText(wxString(statusText));
	 panel->Refresh(); // Refresh the display
}

//grid initialize
void MainWindow::GridInitialize()
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

void MainWindow::SetStatusBarText(const wxString& text)
{
	statusBar->SetStatusText(text);
}

MainWindow::~MainWindow()
{

}