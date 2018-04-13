#include "Engine_pch.h"
#include "InputManager.h"
#include "Engine.h"


CInputManager::CInputManager()
{
}


CInputManager::~CInputManager()
{
}

void CInputManager::RegisterInputCallback(IInputListener* listener)
{
	m_listeners.push_back(listener);
}

void CInputManager::UnregisterInputCallback(IInputListener* listener)
{
	for (auto itr = m_listeners.begin(); itr != m_listeners.end(); ++itr)
	{
		if ((*itr) == listener)
		{
			m_listeners.erase(itr);
			break;
		}
	}
}

void CInputManager::ProcessInputs()
{
	SDL_Event e;
	m_inputInfos.clear();
	while (SDL_PollEvent(&e) != 0)
	{
		switch(e.type)
		{
		case SDL_QUIT:
			CEngine::GetInstance().RequestShutdown();
			break;
		
		case SDL_MOUSEBUTTONDOWN:
			int x, y;
			SDL_GetMouseState(&x, &y);
			InputInfo info;
			info.m_inputType = EInputType_Mouse;
			info.m_inputInteraction = EInputInteraction_Pressed;
			info.m_inputInfoData.m_inputInfoMouse.m_x = x;
			info.m_inputInfoData.m_inputInfoMouse.m_y = y;
			m_inputInfos.push_back(info);
		}
	}
	DispatchInputs();
}

void CInputManager::DispatchInputs()
{
	for (auto itr = m_listeners.begin(); itr != m_listeners.end(); ++itr)
	{
		(*itr)->OnInputEvent(m_inputInfos);
	}
}
