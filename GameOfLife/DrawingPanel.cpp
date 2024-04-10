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

	context->SetPen(*wxBLACK);
	context->SetBrush(*wxWHITE);
	context->DrawRectangle(0, 0, 10, 10);
	context->DrawRectangle(10, 0, 10, 10);

	context->DrawRectangle(0, 0, 10, 10);
}

DrawingPanel::~DrawingPanel()
{

}