#pragma once

#ifdef WN_PLATFORM_WINDOWS

extern Walnut::Application* Walnut::CreateApplication();
// Q: why extern here?

// start point is in SandBox(exe), this main will be included and called in sanbox
int main(int argc, char** argv) 
{
	Walnut::Log::Init();
	WN_CORE_WARN("engine init logs");
	int a = 1;
	WN_CLIENT_INFO("Hello! Var={0}", a);
	auto app = Walnut::CreateApplication();
	app->Run();
	delete app;

}

#endif

