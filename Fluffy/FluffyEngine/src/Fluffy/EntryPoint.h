#pragma once
#include "Application.h"

extern Fluffy::Application * Fluffy::CreateApplication();

int main(int _argc, char ** _argv)
{

	Fluffy::Log::Init();

	F_CORE_TRACE("Logger Initialized");
	F_APP_TRACE("Logger Initialized");

	auto app = Fluffy::CreateApplication();

	app->Run();

	delete app;

	return 0;

}