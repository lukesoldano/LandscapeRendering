
#include <iostream>

#include "Application.hpp"

int main()
{
    std::cout << "Hello World!\n";

    auto& application = Application::instance();

    application.run();

    application.terminate();
}
