#include "Window.hpp"

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <iostream>

Window::Window(int width, int height) :
   m_width(width),
   m_height(height)
{

}

Window::~Window()
{
   if (m_glfw_window)
   {
      glfwDestroyWindow(m_glfw_window);
      m_glfw_window = nullptr;
   }
}

bool Window::initialize()
{
   if (m_glfw_window)
      return true; // do nothing

   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);

   m_glfw_window = glfwCreateWindow(m_width, m_height, "My Window", nullptr, nullptr);
   if (!m_glfw_window)
   {
      std::cout << "glfwCreateWindow() failed!" << std::endl;
      return false;
   }

   glfwMakeContextCurrent(m_glfw_window);

   return true;
}

bool Window::should_close() const
{
   if (!m_glfw_window)
      return true;

   return glfwWindowShouldClose(m_glfw_window) == GLFW_TRUE;
}