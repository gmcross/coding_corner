#pragma once
#include <SDL2/SDL.h>

#include "sdl_interface/widget.h"

namespace sdl_interface {

// Forward declaration for the Widget base class
class Widget;

class RendererBase {
public:
  virtual ~RendererBase() = default;
  virtual void clear() = 0;
  virtual void update() = 0;
  virtual void renderWidget(Widget &widget) = 0;
};

class Renderer : public RendererBase {
public:
  Renderer(SDL_Window *window);

  ~Renderer() override;

  void clear() override;
  void update() override;

  void renderWidget(Widget &widget) override;

private:
  SDL_Renderer *renderer_;
};
}  // namespace sdl_interface
