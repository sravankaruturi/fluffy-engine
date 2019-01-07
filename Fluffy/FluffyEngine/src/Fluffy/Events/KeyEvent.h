#pragma once

#include "Event.h"

namespace Fluffy
{
	
	class F_API KeyEvent : public Event
	{

	protected:

		int m_KeyCode;

		KeyEvent(int _keyCode)
			: m_KeyCode(_keyCode)
		{
			
		}

	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	};

	class F_API KeyPressedEvent : public KeyEvent
	{
	private:
		int m_RepeatCount;

	public:
		KeyPressedEvent(int _keyCode, int _repeatCount)
			:KeyEvent(_keyCode), m_RepeatCount(_repeatCount)
		{
			
		}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	class F_API KeyReleasedEvent: public KeyEvent
	{
	public:
		KeyReleasedEvent(int _keyCode)
			: KeyEvent(_keyCode)
		{
			
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}