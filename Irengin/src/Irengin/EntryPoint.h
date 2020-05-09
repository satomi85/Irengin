#pragma once

#ifdef IRNGN_PLATFORM_WINDOWS

extern Irengin::Application* Irengin::CreateApplication();

void main(int argc, char** argv)
{
	Irengin::Log::Init();
	IRNGN_CORE_WARN("Initialided Log");
	int a = 5;
	IRNGN_INFO("Var={0}", a);

	auto app = Irengin::CreateApplication();
	app->Run();
	delete app;
}

#endif