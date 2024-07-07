#include "sdl_interface/rectangle.h"

namespace sdl_interface {

Rectangle::Rectangle(const int x, const int y, const int width, const int height) {
  rect_.x = x;
  rect_.y = y;
  rect_.w = width;
  rect_.h = height;
}

void Rectangle::setPosition(const int x, const int y) {
  rect_.x = x;
  rect_.y = y;
}

void Rectangle::update(RendererBase &renderer) { renderer.renderWidget(*this); }

void Rectangle::draw(SDL_Renderer *renderer) const {
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderDrawRect(renderer, &rect_);
}

bool Rectangle::contains(const int x, const int y) const {
  const auto topRightX = rect_.x + rect_.w;
  const auto topRightY = rect_.y + rect_.h;
  return (x >= rect_.x && x <= topRightX && y >= rect_.y && y <= topRightY);
}

}  // namespace sdl_interface
