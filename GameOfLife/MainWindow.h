#pragma once
#include "wx/wx.h"
//#include "DrawingPanel.h"
#include "MainWindow.h"
class DrawingPanel;
class MainWindow : public wxFrame
{
	DrawingPanel* panel = nullptr; // all variables in header files need to be intialize 
	wxBoxSizer* boxSizer = nullptr;
	int generation;
	int livingCells;
	wxStatusBar* statusBar;
	wxToolBar* toolBar;
	
public:
	static const int PLAY_ID = 10813;
	static const int PAUSE_ID = 10654;
	static const int NEXT_ID = 10433;
	static const int TRASH_ID = 10999;
	MainWindow();
	~MainWindow();
	void OnSizeChange(wxSizeEvent&);
	void GridInitialize();
	void SetStatusBarText(const wxString &text);
	void OnPlay(wxCommandEvent&);
	void OnPause(wxCommandEvent&);
	void OnNext(wxCommandEvent&);
	void OnTrash(wxCommandEvent&);
	int NeighborCount(int x, int y);
	void NextGeneration();
	std::vector<std::vector<bool>> gridstates;
	int GridSize = 15;
	wxDECLARE_EVENT_TABLE();
};

