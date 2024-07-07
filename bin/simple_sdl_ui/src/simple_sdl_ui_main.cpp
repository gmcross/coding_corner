#include <sdl_interface/rectangle.h>
#include <sdl_interface/widget_manager.h>
#include <sdl_interface/window.h>

#include <iostream>

int main() {
  sdl_interface::Window window("Simple SDL UI", 800, 600);

  auto widget_manager = std::make_shared<sdl_interface::WidgetManager>();
  auto rectangle = std::make_shared<sdl_interface::Rectangle>(100, 100, 10, 10);
  widget_manager->addWidget(rectangle);

  while (true) {
    window.clear();

    SDL_Event event;
    if (SDL_PollEvent(&event)) {
      std::cout << "Event type: " << event.type << std::endl;
      if (event.type == SDL_QUIT) {
        break;
      } else if (event.type == SDL_MOUSEMOTION) {
        widget_manager->onMouseMotion(event.motion.x, event.motion.y);
      }
      window.update(widget_manager);
    }
  }

  return 0;
}
