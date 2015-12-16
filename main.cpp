// Remove later

#include "Deviant/Runtime/Application.hpp"
#include "Deviant/Utilities/Singleton.hpp"
#include "Deviant/Utilities/Debug.hpp"

int main(int argc, char* args[])
{
    try
    {
        dv::Application::Initialize("Deviant Application", 800, 600, 800, 600, 30, VERBOSITY_ALL);
    }
    catch (std::string e)
    {
        dv::Debug::out(e);
    }

    return dv::Application::Run();
}
