#pragma once

#include "Window.hpp"

#include <memory>

class Application
{
   std::unique_ptr<Window> m_window;

public:

   static Application& instance();

   void run();
   void terminate();

private:

   bool initialize();

};

