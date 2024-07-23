#include "pch.h"
#include "RenderFrame.h"

const wxWindowID ID_RENDER_TIMER = 6001;
const wxWindowID ID_DEFERED_RESIZE_TIMER = 6002;


RenderFrame::RenderFrame(wxWindow* window, wxWindowID id, const wxString& title)
: wxFrame(window, id, title)
, m_timer{}
, m_deferredSizingTimer{}
{
	g1::CreateFactory(&m_module);
	m_module->CreateRenderManager(&m_renderManager);
	m_firstShowHandler = [this](wxShowEvent& event)
		{
			auto size = GetClientSize();
			m_prevSize = size;
			m_module->CreateRenderTarget(GetHWND(), size.GetWidth(), size.GetHeight(), &m_renderTarget);
			
			Bind(wxEVT_SIZE, &RenderFrame::OnFrameSized, this);

			m_timer = new wxTimer{ this, ID_RENDER_TIMER};
			m_timer->Start(16);
			m_module->CreateObject(&m_obj);
			CallAfter([this]() { m_firstShowHandler = {}; });
			Unbind(wxEVT_SHOW, m_firstShowHandler);
		};
	Bind(wxEVT_SHOW, m_firstShowHandler);
	Bind(wxEVT_TIMER, [this](wxTimerEvent& evt)
		{
			m_renderManager->Render(m_renderTarget.Get());
			m_renderTarget->Present();
		}, ID_RENDER_TIMER);

	Bind(wxEVT_TIMER, &RenderFrame::OnDeferredSizedTimer, this, ID_DEFERED_RESIZE_TIMER);

}

RenderFrame::~RenderFrame()
{
	if(m_timer != nullptr) 
	{
		m_timer->Stop();
		delete m_timer;
	}
}

void RenderFrame::OnDeferredSizedTimer(wxTimerEvent& event)
{
	if (m_deferredSizingTimer == nullptr)
	{
		return;
	}

	delete m_deferredSizingTimer;
	m_deferredSizingTimer = nullptr;

	auto size = GetClientSize();

	if (m_prevSize == size)
	{
		return;
	}

	m_prevSize = size;
	m_renderTarget->Resize(size.GetWidth(), size.GetHeight());
}

void RenderFrame::OnFrameSized(wxSizeEvent& event)
{
	if (m_deferredSizingTimer != nullptr)
	{
		m_deferredSizingTimer->Stop();
		m_deferredSizingTimer->DeletePendingEvents();
		delete m_deferredSizingTimer;
		m_deferredSizingTimer = nullptr;
	}

	m_deferredSizingTimer = new wxTimer{ this, ID_DEFERED_RESIZE_TIMER };
	m_deferredSizingTimer->StartOnce(150);
}
