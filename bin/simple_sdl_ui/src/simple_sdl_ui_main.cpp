#include <sdl_interface/rectangle.h>
#include <sdl_interface/widget_manager.h>
#include <sdl_interface/window.h>

int main() {
  sdl_interface::Window window("Simple SDL UI", 800, 600);

  auto widget_manager = std::make_shared<sdl_interface::WidgetManager>();
  auto rectangle = std::make_shared<sdl_interface::Rectangle>(100, 100, 10, 10);
  widget_manager->addWidget(rectangle);

  while (true) {
    window.clear();

    SDL_Event event;
    if (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        break;
      }
      else if (event.type == SDL_MOUSEMOTION) {
        widget_manager->onMouseMotion(event.motion.x, event.motion.y);
      }
      // else if (event.type == SDL_MOUSEBUTTONDOWN) {
      //   widget_manager->onMouseButtonDown(event.button.x, event.button.y);
      // }
      // else if (event.type == SDL_MOUSEBUTTONUP) {
      //   widget_manager->onMouseButtonUp(event.button.x, event.button.y);
      // }
    }

    window.update(widget_manager);
  }

  return 0;
}
