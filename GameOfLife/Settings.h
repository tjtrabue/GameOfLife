#pragma once
#include "wx/wx.h"
#include <fstream>

struct Settings
{
	//living cells
	unsigned int RedL = 128;//128
	unsigned int BlueL = 128;
	unsigned int GreenL = 128;
	unsigned int AlphaL = 255;

	//dead
	unsigned int RedD = 255;//255
	unsigned int BlueD = 255;
	unsigned int GreenD = 255;
	unsigned int AlphaD = 255;

	int gridSize = 15;
	int interval = 500;
	bool showNeighborCount = false;

	wxColor GetLivingCellColor()
	{
		return wxColor(RedL, GreenL, BlueL, AlphaL);
	}

	wxColor GetDeadCellColor()
	{
		return wxColor(RedD, GreenD, BlueD, AlphaD);
	}

	void SetLivingCellColor(wxColor color)
	{
		RedL = color.Red();
		BlueL = color.Blue();
		GreenL = color.Green();
		AlphaL = color.Alpha();
	}

	void SetDeadCellColor(wxColor color)
	{
		RedD = color.Red();
		BlueD = color.Blue();
		GreenD = color.Green();
		AlphaD = color.Alpha();
	}

	void SaveData()
	{
		//Save Data
		std::ofstream file("settings.bin", std::ios::out | std::ios::binary);
		file.write((char*)this, sizeof(Settings));
		file.close();
	}

	void LoadData()
	{
		//Load Data
		std::ifstream file("settings.bin", std::ios::binary | std::ios::in);
		file.read((char*)this, sizeof(Settings));
		file.close();
	}
};