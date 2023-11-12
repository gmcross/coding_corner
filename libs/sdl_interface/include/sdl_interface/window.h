#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <memory>

#include "sdl_interface/renderer.h"

namespace sdl_interface
{
    class Window
    {
    public:
        Window(const std::string& title, int width, int height);
        ~Window();

        void clear();
        void update();

        SDL_Window* getWindow() const { return window_; }
        std::shared_ptr<Renderer> getRenderer() const { return renderer_; }

    private:
        SDL_Window* window_;
        std::shared_ptr<Renderer> renderer_;
    };
} // namespace sdl_interface
