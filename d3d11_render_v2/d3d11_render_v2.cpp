// d3d11_render_v2.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "d3d11_render_v2.h"
#include "RenderFrame.h"

#pragma comment(lib, "d3d11graphicsmodule.lib")

#define MAX_LOADSTRING 100


wxIMPLEMENT_APP(RenderD3d11V2App);

bool RenderD3d11V2App::OnInit()
{
	m_pFrame = new RenderFrame{ nullptr, wxID_ANY, wxS("Render Frame") };
	m_pFrame->Show();

	return true;
}

int RenderD3d11V2App::OnExit()
{
	int ret = wxApp::OnExit();
	return ret;
}
