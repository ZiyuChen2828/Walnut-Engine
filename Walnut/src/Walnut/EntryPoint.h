#pragma once



#ifdef WN_PLATFORM_WINDOWS

extern Walnut::Application* Walnut::CreateApplication();


// start point is in SandBox(exe), this main will be included and called in sanbox
int main(int argc, char** argv) 
{
	printf("engine start");
	auto app = Walnut::CreateApplication();
	app->Run();
	delete app;

}

#endif