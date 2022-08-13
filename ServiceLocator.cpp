#include "ServiceLocator.h"
// ------------------- Service Base Interface -------------------
int IService::s_currentId = -1;

IService::IService()
{
    m_id = ++s_currentId;
}

IService::~IService()
{
    m_id = -999;
    --s_currentId;
}
// ------------------- Service Base Interface -------------------



// ------------------- Static Locator Class -------------------
Locator* Locator::s_instance = nullptr;

Locator* Locator::Instance()
{
	if (s_instance == nullptr)
		s_instance = new Locator();

	return s_instance;
}

void Locator::Shutdown()
{
	Instance()->ShutdownImpl();
}
void Locator::ShutdownImpl()
{
	for (const auto& [key, value] : m_services)
	{
		std::cout << "Deleting service: " << key << std::endl;
        m_services.erase((key));
	}
}
// ------------------- Static Locator Class -------------------