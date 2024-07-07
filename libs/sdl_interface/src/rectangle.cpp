#include "sdl_interface/rectangle.h"

#include <iostream>

namespace sdl_interface {

Rectangle::Rectangle(const int x, const int y, const int width, const int height) {
  rect_.x = x;
  rect_.y = y;
  rect_.w = width;
  rect_.h = height;
}

Rectangle::~Rectangle() {}

void Rectangle::setPosition(const int x, const int y) {
  rect_.x = x;
  rect_.y = y;
}

void Rectangle::update(RendererBase &renderer) {
  std::cout << "Rectangle::update" << std::endl;
  renderer.renderWidget(*this);
}

void Rectangle::draw(SDL_Renderer *renderer) const {
  std::cout << "Rectangle::draw" << std::endl;
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderDrawRect(renderer, &rect_);
}

bool Rectangle::contains(const int x, const int y) const {
  const auto topRightX = rect_.x + rect_.w;
  const auto topRightY = rect_.y + rect_.h;

  if (x >= rect_.x && x <= topRightX && y >= rect_.y && y <= topRightY) {
    std::cout << "Rectangle contains point (" << x << ", " << y << ")" << std::endl;
    return true;
  }
  return false;
}

}  // namespace sdl_interface
