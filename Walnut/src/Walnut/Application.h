#pragma once

#include "Core.h"

namespace Walnut {

	class WN_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// To be defined in client
	Application* CreateApplication();

}