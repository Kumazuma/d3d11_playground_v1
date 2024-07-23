#pragma once
#include <wx/wx.h>
#include <wrl.h>
#include "interface.h"

class RenderFrame: public wxFrame
{
public:
	RenderFrame(wxWindow* window, wxWindowID id, const wxString& title);
	
	~RenderFrame();

protected:
	void OnDeferredSizedTimer(wxTimerEvent& event);

	void OnFrameSized(wxSizeEvent& event);

private:
	Microsoft::WRL::ComPtr<g1::IFactory> m_module;
	Microsoft::WRL::ComPtr<g1::IWindowRenderTarget> m_renderTarget;
	Microsoft::WRL::ComPtr<g1::IRenderManager> m_renderManager;
	Microsoft::WRL::ComPtr<g1::IObject> m_obj;
	wxTimer* m_timer;
	wxTimer* m_deferredSizingTimer;
	std::function<void(wxShowEvent& evt)> m_firstShowHandler;
	wxSize m_prevSize;
};

