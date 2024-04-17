#pragma once
#include "wx/wx.h"
#include "Settings.h"
#include "wx/spinctrl.h"
#include "wx/clrpicker.h"


class SettingsDialog : public wxDialog
{
private:
	Settings* setting;
	wxSpinCtrl* gridSizeCtrl;
	wxSpinCtrl* intervalCtrl;
	wxColourPickerCtrl* livingColorCtrl;
	wxColourPickerCtrl* deadColorCtrl;
	static const int GRIDSIZE_ID = 11000;
	static const int INTERVAL_ID = 11500;
	static const int LIVINGCOLOR_ID = 11200;
	static const int DEADCOLOR_ID = 11356;

public:
	SettingsDialog(wxWindow* parentWindow, Settings* setting) : wxDialog(parentWindow,wxID_ANY,"Settings Dialog")
	{
		this->setting = setting;
		wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
		this->SetSizer(boxSizer);
		//horizontal
		wxBoxSizer* gridSizeSizer = new wxBoxSizer(wxHORIZONTAL);
		gridSizeCtrl = new wxSpinCtrl(this, GRIDSIZE_ID);
		wxStaticText* gridSizeText = new wxStaticText(this, wxID_ANY, "Grid Size");
		gridSizeSizer->Add(gridSizeText);
		gridSizeSizer->Add(gridSizeCtrl);
		boxSizer->Add(gridSizeSizer);
		//interval
		wxBoxSizer* intervalSizer = new wxBoxSizer(wxHORIZONTAL);
		intervalCtrl = new wxSpinCtrl(this, INTERVAL_ID);
		wxStaticText* intervalText = new wxStaticText(this, wxID_ANY, "Interval");
		intervalSizer->Add(intervalText);
		intervalSizer->Add(intervalCtrl);
		boxSizer->Add(intervalSizer);
		//living color
		wxBoxSizer* livingColorSizer = new wxBoxSizer(wxHORIZONTAL);
		livingColorCtrl = new wxColourPickerCtrl(this, LIVINGCOLOR_ID);
		wxStaticText* livingColorText = new wxStaticText(this, wxID_ANY, "Living Color");
		livingColorSizer->Add(livingColorText);
		livingColorSizer->Add(livingColorCtrl);
		boxSizer->Add(livingColorSizer);
		//dead color
		wxBoxSizer* deadColorSizer = new wxBoxSizer(wxHORIZONTAL);
		deadColorCtrl = new wxColourPickerCtrl(this, DEADCOLOR_ID);
		wxStaticText* deadColorText = new wxStaticText(this, wxID_ANY, "Living Color");
		deadColorSizer->Add(deadColorText);
		deadColorSizer->Add(deadColorCtrl);
		boxSizer->Add(deadColorSizer);

		wxSizer* okCancelSizer = CreateButtonSizer(wxOK | wxCANCEL);
		boxSizer->Add(okCancelSizer);

		gridSizeCtrl->SetValue(setting->gridSize);
		intervalCtrl->SetValue(setting->interval);
		livingColorCtrl->SetColour(setting->GetLivingCellColor());
		deadColorCtrl->SetColour(setting->GetDeadCellColor());


		

	}
	void onOK(wxCommandEvent&);
	void onCancel(wxCommandEvent&);
	wxDECLARE_EVENT_TABLE();
};

