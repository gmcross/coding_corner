#include "sdl_interface/renderer.h"

namespace sdl_interface {

Renderer::Renderer(SDL_Window *window) {
  renderer_ = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Renderer::~Renderer() { SDL_DestroyRenderer(renderer_); }

void Renderer::clear() {
  // Set render color to black
  SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
  SDL_RenderClear(renderer_);
}

void Renderer::update() { SDL_RenderPresent(renderer_); }

void Renderer::renderWidget(Widget &widget) {
  widget.draw(renderer_);
  SDL_RenderPresent(renderer_);
}

}  // namespace sdl_interface
