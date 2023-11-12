#include <sdl_interface/window.h>

int main() {
  sdl_interface::Window window("Simple SDL UI", 800, 600);
  window.clear();
  window.update();
  
  while (true) {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        break;
      }
    }
  }

  return 0;
}
