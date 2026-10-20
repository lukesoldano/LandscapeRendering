#include "Application.hpp"

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <chrono>
#include <iostream>
#include <thread>

namespace
{
   constexpr const double FRAME_TIME = 1.0f / 30.0f;

   void error_callback(int err, const char* err_str)
   {
      std::cout << "!!! GLFW ERROR: " << err << " - " << err_str << std::endl;
   }
}

Application& Application::instance()
{
   static Application* s_instance = nullptr;
   if (!s_instance)
   {
      s_instance = new Application();
      if (!s_instance->initialize())
      {
         std::cout << "Failed to initialize Application!" << std::endl;
         delete s_instance;
      }
   }

   return *s_instance;
}

bool Application::initialize()
{
   if (glfwInit() != GLFW_TRUE)
   {
      std::cout << "glfwInit() failed!" << std::endl;
      terminate();
      return false;
   }

   glfwSetErrorCallback(error_callback);

   m_window = std::make_unique<Window>();
   if (!m_window->initialize())
   {
      std::cout << "m_window->initialize() failed!" << std::endl;
      terminate();
      return false;
   }

   return true;
}

void Application::terminate()
{
   m_window.reset();
   m_window = nullptr;

   glfwTerminate();
}

void Application::run()
{
   if (!m_window)
      return;

   double current_frame = glfwGetTime();
   double last_frame = current_frame;

   while (!m_window->should_close())
   {
      current_frame = glfwGetTime();
      double delta_time = current_frame - last_frame;

      if (FRAME_TIME > delta_time)
      {
         std::this_thread::sleep_for(std::chrono::milliseconds(1));
         continue;
      }

      last_frame = current_frame;
   }
}