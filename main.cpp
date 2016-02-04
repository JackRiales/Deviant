// Remove later
#define TEST_TRANSFORMS 0
#define TEST_CONFIG 0

#include "Deviant/Runtime/Application.hpp"
#include "Deviant/Utilities/Transform.hpp"
#include "Deviant/Management/Configuration.hpp"
#include "Deviant/Utilities/Debug.hpp"
#include <iostream>
using namespace dv;

int main(int argc, char* args[]) {
	try {
		Application::Initialize("Deviant Application", 800, 600, 800, 600, 30, VERBOSITY_ALL);
	} catch (std::string e) {
		Debug::out(e);
		exit(1);
	}

    if (TEST_TRANSFORMS) {
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
        std::cout << "===============\nENDING TEST OF TRANSFORMS\n" << std::endl;
    }

    if (TEST_CONFIG) {
        std::cout << "TESTING CONFIG\n===============" << std::endl;
        /* WRITING */
        ConfigManager::AddConfig("MySet", "MyKey1", "MyValue1");
        ConfigManager::AddConfig("MySet", "MyKey2", "MyValue2");
        ConfigManager::AddConfig("MySet", "MyKey3", "MyValue3");
        ConfigManager::AddConfig("MyKey4", "MyValue4");
        ConfigManager::WriteAll("TestConfig");

        /* READING */
        ConfigManager::Read("TestConfig");
        ConfigManager::WriteAll("TestConfig2");
        std::cout << "===============\nENDING TEST OF CONFIG\n" << std::endl;
    }

	return Application::Run();
}
