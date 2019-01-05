#pragma once

#include "Core.h"

namespace Fluffy {

	class F_API Application
	{
	public:

		Application();

		virtual ~Application();

		void Run();

	};

	// To be defined in the Client
	Application * CreateApplication();

}