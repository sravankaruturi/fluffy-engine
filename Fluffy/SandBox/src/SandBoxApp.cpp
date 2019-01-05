

#include "Fluffy.h"

class Sandbox : public Fluffy::Application
{
public:

	Sandbox() = default;

	~Sandbox() = default;

};

Fluffy::Application* Fluffy::CreateApplication()
{
	return new Sandbox();
}