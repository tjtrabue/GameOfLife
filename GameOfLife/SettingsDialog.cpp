#include "SettingsDialog.h"
wxBEGIN_EVENT_TABLE(SettingsDialog, wxDialog)
EVT_BUTTON(wxID_OK,SettingsDialog::onOK)
EVT_BUTTON(wxID_CANCEL, SettingsDialog::onCancel)
wxEND_EVENT_TABLE()

void SettingsDialog::onOK(wxCommandEvent&)
{
	setting->SetDeadCellColor(deadColorCtrl->GetColour());
	setting->SetLivingCellColor(livingColorCtrl->GetColour());
	setting->gridSize = gridSizeCtrl->GetValue();
	setting->interval = intervalCtrl->GetValue();
	EndModal(wxID_OK);
}

void SettingsDialog::onCancel(wxCommandEvent&)
{
	gridSizeCtrl->SetValue(setting->gridSize);
	intervalCtrl->SetValue(setting->interval);
	livingColorCtrl->SetColour(setting->GetLivingCellColor());
	deadColorCtrl->SetColour(setting->GetDeadCellColor());
	EndModal(wxID_CANCEL);

}
