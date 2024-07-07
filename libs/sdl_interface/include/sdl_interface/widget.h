#pragma once
#include "sdl_interface/renderer.h"
#include <memory>

namespace sdl_interface {

class RendererBase;
class Widget {
public:
  virtual ~Widget() = default;

  virtual void update(const std::shared_ptr<RendererBase> &renderer) = 0;

  virtual void draw( SDL_Renderer * renderer) const = 0;

  virtual void onMouseMotion(int x, int y) = 0;
};
}  // namespace sdl_interface
