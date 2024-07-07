/**
 * @file window.h
 * @brief This file provides a Window class that can be used to create a window and renderer.
 * @date 07/06/2024
 */
#pragma once

#include <SDL2/SDL.h>

#include <memory>
#include <string>

#include "sdl_interface/renderer.h"
#include "sdl_interface/widget_manager.h"

namespace sdl_interface {

/**
 * @class  Window
 * @brief  This class will create a window and renderer.
 *         Its role is to present the widgets in the widget manager, using the renderer.
 *
 *          The key features of this class are:
 *              1. Provides an interface to create a window and renderer widgets
 */
class Window {
public:
  /**
   * @brief Constructor for the Window class.
   *
   * @param title The title of the window.
   * @param width The width of the window.
   * @param height The height of the window.
   */
  Window(const std::string &title, int width, int height);

  /**
   * @brief Destructor for the Window class.
   */
  ~Window();

  /**
   * @brief Method to clear the window.
   *        This will call upon the renderer to clear the screen.
   */
  void clear();

  /**
   * @brief Method to update the window.
   *        This will call upon all the widgets in the widget manager to update.
   *
   * @param widget_manager The widget manager to be used to update the widgets.
   */
  void update(const std::shared_ptr<WidgetManager> &widget_manager);

  /**
   * @brief Provides the SDL window.
   *
   * @return The SDL window.
   */
  SDL_Window *getWindow() const { return window_; }

  /**
   * @brief Provides the renderer.
   *
   * @return The renderer.
   */
  std::shared_ptr<Renderer> getRenderer() const { return renderer_; }

private:
  /// The SDL window to be rendered.
  SDL_Window *window_;
  /// The renderer to be used to render the widgets.
  std::shared_ptr<Renderer> renderer_;
};
}  // namespace sdl_interface
