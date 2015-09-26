// Remove later

#include "Deviant/Base/Application.hpp"

int main(int argc, char* args[]) {
    dv::Application::Initialize("Deviant Application", 800, 600, 800, 600, 30, VERBOSITY_ALL);
    return dv::Application::Run();
}
