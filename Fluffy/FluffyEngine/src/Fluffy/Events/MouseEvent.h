﻿#pragma once

#include "Event.h"

namespace Fluffy
{
	class F_API MouseMovement : public Event
	{
	
	private:
		float m_MouseX, m_MouseY;

	public:
		MouseMovement(float _x, float _y)
			: m_MouseX(_x), m_MouseY(_y)
		{
			
		}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	};

	class F_API MouseScrolledEvent : public Event
	{
	private:
		float m_XOffset, m_YOffset;
	public:
		MouseScrolledEvent(float _xOffset, float _yOffset)
			: m_XOffset(_xOffset), m_YOffset(_yOffset)
		{
			
		}

		inline float GetXOffSet() const { return m_XOffset; }
		inline float GetYOffSet() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffSet() << ", " << GetYOffSet();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class F_API MouseButtonEvent: public Event
	{
	protected:
		int m_Button;

		MouseButtonEvent(int _button)
			: m_Button(_button)
		{
			
		}

	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
	};

	class F_API MouseButtonPressedEvent: public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int _button)
			: MouseButtonEvent(_button)
		{
			
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class F_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int _button)
			: MouseButtonEvent(_button)
		{

		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}