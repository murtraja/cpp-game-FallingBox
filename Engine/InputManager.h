#pragma once

#include "InputTypes.h"

class IInputListener
{
public:
	virtual void OnInputEvent(std::vector<InputInfo>) = 0;
};

class CInputManager
{
	std::vector<IInputListener*> m_listeners;
	std::vector<InputInfo> m_inputInfos;
public:
	CInputManager();
	~CInputManager();
	void RegisterInputCallback(IInputListener* listener);
	void UnregisterInputCallback(IInputListener* listener);
	void ProcessInputs();
	void DispatchInputs();
};

