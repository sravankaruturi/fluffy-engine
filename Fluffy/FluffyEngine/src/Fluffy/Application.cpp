#include "fpch.h"
#include "Application.h"

#include "Fluffy/Events/ApllicationEvent.h"
#include "Fluffy/Log.h"

namespace Fluffy
{
	Application::Application()
	{
	}

	Application::~Application() = default;

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if ( e.IsInCategory(EventCategoryApplication))
		{
			F_CORE_TRACE(e.ToString())
		}
		//if (e.IsInCategory(EventCategoryInput))
		//{
		//	F_CORE_TRACE(e);
		//}

		while (true)
		{
			
		}
	}

}
