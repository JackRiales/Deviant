// Remove later

#include "Deviant/Runtime/Application.hpp"
#include "Deviant/Utilities/Transform.hpp"
#include "Deviant/Utilities/Debug.hpp"
#include <iostream>
using namespace dv;

int main(int argc, char* args[])
{
    try
    {
        Application::Initialize("Deviant Application", 800, 600, 800, 600, 30, VERBOSITY_ALL);
    }
    catch (std::string e)
    {
        Debug::out(e);
    }

    std::cout << "TESTING TRANSFORMS\n===============" << std::endl;
    Transform2D t1;
    Transform2D t2;
    t2.setParent(t1);
    t2.setPosition(30, 40);
    t2.rotate(30);
    t1.translate(100);
    std::cout << "T1\n\tPosition = " << std::to_string(t1.position().x) << ", " << std::to_string(t1.position().y) << std::endl;
    std::cout << "T2\n\tPosition = " << std::to_string(t2.position().x) << ", " << std::to_string(t2.position().y) << std::endl;
    t2.removeParent();
    t1.removeParent();
    std::cout << "===============\nENDING TEST OF TRANSFORMS" << std::endl;


    return Application::Run();
}
