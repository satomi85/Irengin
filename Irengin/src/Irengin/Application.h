#pragma once

#include "Core.h"

namespace Irengin {

	class IRNGN_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}
