#include "Application.h"

#include "Irengin/Events/ApplicationEvents.h"
#include "Irengin/Log.h"

namespace Irengin {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		IRNGN_TRACE(e);

		while (true);
	}
}
