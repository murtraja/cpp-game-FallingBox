#pragma once

enum EInputType
{
	EInputType_Mouse,
	EInputType_Keyboard
};

enum EInputInteraction
{
	EInputInteraction_Pressed,
	EInputInteraction_Released
};

struct InputInfoKeyboard
{

};

struct InputInfoMouse
{
	int m_x, m_y;
};

struct InputInfo
{
	EInputType m_inputType;
	EInputInteraction m_inputInteraction;
	union InputInfoData
	{
		InputInfoKeyboard m_inputInfoKeyboard;
		InputInfoMouse m_inputInfoMouse;
	}m_inputInfoData;
};