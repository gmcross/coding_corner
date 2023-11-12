#include "sdl_interface/rectangle.h"

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

void Rectangle::update(const std::shared_ptr<RendererBase> &renderer) {  
  // renderer->renderWidget(this); 
}
void Rectangle::draw(SDL_Renderer *renderer) const {  
  SDL_RenderFillRect(renderer, &rect_);
}

}  // namespace sdl_interface
