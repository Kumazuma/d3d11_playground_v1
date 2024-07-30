#pragma once

#include "resource.h"
#include <wx/wx.h>

class RenderD3d11V2App : public wxApp
{
public:
	bool OnInit() override;
	
	int OnExit() override;

private:
	wxFrame* m_pFrame = nullptr;
};

wxDECLARE_APP(RenderD3d11V2App);