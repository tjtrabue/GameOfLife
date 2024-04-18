#include "DrawingPanel.h"
#include "MainWindow.h"
#include "wx/wx.h"
#include "wx/graphics.h"
#include "wx/dcbuffer.h"
wxBEGIN_EVENT_TABLE(DrawingPanel, wxPanel)
	EVT_PAINT(DrawingPanel::OnPaint)
	EVT_LEFT_UP(DrawingPanel::OnMouseUp)
wxEND_EVENT_TABLE()
//class MainWindow;

DrawingPanel::DrawingPanel(MainWindow* parent, std::vector<std::vector<bool>>& gameGrid, std::vector<std::vector<int>>& neighborCount) :wxPanel(parent), gameGrid(gameGrid), neighborCount(neighborCount)
{
	
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
	//this->Bind(wxEVT_PAINT, &DrawingPanel::OnPaint, this);
	//this->Bind(wxEVT_LEFT_UP, &DrawingPanel::OnMouseUp, this);
}

void DrawingPanel::OnPaint(wxPaintEvent&)
{
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();

	wxGraphicsContext* context = wxGraphicsContext::Create(dc);

	if (!context) 
	{ 
		return; 
	}

	int cellSize = 10;

	context->SetPen(*wxBLACK);
	context->SetBrush(*wxWHITE);

	// the GetClientSize() is a method of wxPanel's, which our DrawingPanel inherits
	// it returns a wxSize object, which we save
	wxSize mysize = GetClientSize();
	// we calculate cell width by diving the width of the window by the number of cells
	int cellWidth = mysize.GetWidth() / setting->gridSize;
	int cellHeight = mysize.GetHeight() / setting->gridSize;
	bool cellValue;

	// the nested for loops have i and j be every possible pair of numbers from 0 to 15 if gridSize is 16
	for (int i = 0; i < setting->gridSize; i++)
	{


		for (int j = 0; j < setting->gridSize; j++)
		{
			// cellWidth*i is the horizontal coordinate of the left side of rectangle
			// cellHeight*j is the vertical coordinate of the top of the rectangle
			cellValue = gameGrid[j][i];
			if (cellValue == true)
			{
				context->SetBrush(wxBrush(setting->GetLivingCellColor()));
			}
			else
			{
				context->SetBrush(wxBrush(setting->GetDeadCellColor()));
			}

			context->DrawRectangle(cellWidth * i, cellHeight * j, cellWidth, cellHeight);
		}
	}
	
	
}

void DrawingPanel::OnMouseUp(wxMouseEvent& mouseEvent)
{
	int _xValue = mouseEvent.GetX();
	int _yValue = mouseEvent.GetY();
	wxSize mysize = GetSize();
	int cellWidth = mysize.GetWidth() / setting->gridSize;
	int cellHeight = mysize.GetHeight() / setting->gridSize;
	int column = _xValue / cellWidth;
	int row = _yValue / cellHeight;
	if (column >= setting->gridSize || row >= setting->gridSize)
	{
		return;
	}
	bool cellValue = gameGrid[row][column];

	if (cellValue == true)
	{
		cellValue = false;
	}
	else
	{
		cellValue = true;
	}
	gameGrid[row][column] = cellValue; // setting value back into gamegrid

	Refresh();
}

void DrawingPanel::SetSize(const wxSize& _size)
{
	wxPanel::SetSize(_size);
	Refresh();
	
} 

//int DrawingPanel::GetGridSize()
//{

//}

//grid size method
void DrawingPanel::SetGridSize(int newsize)
{
	setting->gridSize = newsize;
}

void DrawingPanel::SetSetting(Settings* setting)
{
	this->setting = setting;
}


DrawingPanel::~DrawingPanel()
{

}