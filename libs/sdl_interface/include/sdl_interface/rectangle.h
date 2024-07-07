#pragma once

#include <SDL2/SDL.h>

#include "sdl_interface/widget.h"

namespace sdl_interface {
class Rectangle : public Widget {
public:
  Rectangle(const int x, const int y, const int width, const int height);
  ~Rectangle();

  void setPosition(const int x, const int y);

  void update(const std::shared_ptr<RendererBase> &renderer) override;
  void draw(SDL_Renderer *renderer) const override;
  void onMouseMotion(int x, int y) override;

private:
  SDL_Rect rect_;
};
}  // namespace sdl_interface
