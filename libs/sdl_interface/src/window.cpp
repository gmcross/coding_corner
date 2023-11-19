#include "sdl_interface/window.h"

namespace sdl_interface {
Window::Window(const std::string &title, int width, int height) {
  window_ =
      SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
  renderer_ = std::make_shared<Renderer>(window_);
}

Window::~Window() {
  renderer_.reset();
  SDL_DestroyWindow(window_);
}

void Window::clear() { 
  renderer_->clear(); }

void Window::update( const std::shared_ptr<WidgetManager>& widget_manager  ) { 
  widget_manager->update(renderer_);  
  renderer_->update();

}
}  // namespace sdl_interface
