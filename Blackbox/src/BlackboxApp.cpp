#include <Irengin.h>

class Blackbox : public Irengin::Application
{
public:
	Blackbox() {}
	~Blackbox() {}
};

Irengin::Application* Irengin::CreateApplication()
{
	return new Blackbox();
}