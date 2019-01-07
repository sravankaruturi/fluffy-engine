#pragma once

#include "Fluffy/Core.h"

#include <string>
#include <functional>

namespace Fluffy
{
	
	// Events are blocking for now.
	// If an event occurs, it needs to be processed immediately.

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication  = BIT(0),
		EventCategoryInput		  = BIT(1),
		EventCategoryKeyboard	  = BIT(2),
		EventCategoryMouse		  = BIT(3),
		EventCategoryMouseButton  = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class F_API Event
	{
		
		friend class EventDispatcher;

	public:

		virtual EventType GetEventType() const = 0;
		virtual const char * GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory _category) const
		{
			return GetCategoryFlags() & _category;
		}

	protected:
		bool m_Handled = false;

	};


	class EventDispatcher
	{
		
		// A Fancy way of storing the Function Pointers.
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& _event)
			: m_Event(_event)
		{
			
		}

		template<typename T>
		bool Dispatch(EventFn<T> _func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;

	};

	inline std::ostream& operator<<(std::ostream& _os, const Event& _e)
	{
		return _os << _e.ToString();
	}

}