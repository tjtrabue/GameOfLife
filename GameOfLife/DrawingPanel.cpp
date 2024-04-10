#include "DrawingPanel.h"
#include "MainWindow.h"
#include "wx/wx.h"
#include "wx/graphics.h"
#include "wx/dcbuffer.h"

//class MainWindow;

DrawingPanel::DrawingPanel(MainWindow* parent) :wxPanel(parent)
{
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
	this->Bind(wxEVT_PAINT, &DrawingPanel::OnPaint, this);

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
	int cellWidth = mysize.GetWidth() / gridSize;
	int cellHeight = mysize.GetHeight() / gridSize;

	// the nested for loops have i and j be every possible pair of numbers from 0 to 15 if gridSize is 16
	for (int i = 0; i < gridSize; i++)
		for (int j = 0; j < gridSize; j++)
			// cellWidth*i is the horizontal coordinate of the left side of rectangle
			// cellHeight*j is the vertical coordinate of the top of the rectangle
			context->DrawRectangle(cellWidth * i, cellHeight * j, cellWidth, cellHeight);

	

}

DrawingPanel::~DrawingPanel()
{

}