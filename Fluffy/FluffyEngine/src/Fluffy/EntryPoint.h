#pragma once
#include "Application.h"
#include <cstdio>

extern Fluffy::Application * Fluffy::CreateApplication();

int main(int argc, char ** argv)
{

	printf("Fluffy Engine Initialized");

	auto app = Fluffy::CreateApplication();

	app->Run();

	delete app;

	return 0;

}