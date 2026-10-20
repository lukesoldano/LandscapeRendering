#pragma once

struct GLFWwindow;

class Window
{
   int m_width = 800;
   int m_height = 600;

   GLFWwindow* m_glfw_window = nullptr;

public:
   
   Window() = default;
   Window(int width, int height);
   Window(const Window&) = delete;
   Window(Window&&) = default;
   virtual ~Window();

   Window& operator=(const Window&) = delete;

   bool initialize();

   bool should_close() const;
};

