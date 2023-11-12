#pragma once
#include <SDL2/SDL.h>
#include "sdl_interface/widget.h"

namespace sdl_interface {
class RendererBase {
public:
  virtual ~RendererBase() = default;
  virtual void clear() = 0;
  virtual void update() = 0;
};

class Widget;
class Renderer : public RendererBase {
public:
  Renderer(SDL_Window *window) {
    renderer_ = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  }
  ~Renderer() override = default;

  void clear() override { SDL_RenderClear(renderer_); }
  void update() override { SDL_RenderPresent(renderer_); }

  void renderWidget(Widget *widget) { /* widget->draw(renderer_); */ }

private:
  SDL_Renderer *renderer_;
};
}  // namespace sdl_interface
