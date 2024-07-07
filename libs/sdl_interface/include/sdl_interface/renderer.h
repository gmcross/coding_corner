/**
 * @file renderer.h
 * @brief This file provides the interface for the SDL Renderer, with a base class and a derived class
 * @date 07/06/2024
 */

#pragma once
#include <SDL2/SDL.h>

#include "sdl_interface/widget.h"

namespace sdl_interface {

/// Forward declaration for the Widget base class
/// The Widget will an abstract class that will provide the interface for all widgets.
class Widget;

/**
 * @class RendererBase
 * @brief This base class will provide an abstract interface for the Renderer class.
 */
class RendererBase {
public:
  /**
   * @brief Virtual destructor for the RendererBase class.
   */
  virtual ~RendererBase() = default;

  /**
   * @brief Clear calls upon the renderer to clear the screen and set the render color to black.
   */
  virtual void clear() = 0;

  /**
   * @brief Update calls upon the renderer to present the screen.
   */
  virtual void update() = 0;

  /**
   * @brief RenderWidget calls upon the renderer to render the passed widget.
   * @param widget The widget to be rendered.
   */
  virtual void renderWidget(Widget &widget) = 0;
};

/**
 * @class Renderer
 * @brief This class will provide the functionality to render widgets to the screen using SDL.
 *        The key features of this class are:
 *          1. Provides a interface to render widgets to an SDL screen.
 */
class Renderer : public RendererBase {
public:
  /**
   * @brief Constructor for the Renderer class.
   * @param window The SDL window to render to.
   */
  Renderer(SDL_Window *window);

  /**
   * @brief Destructor for the Renderer class.
   */
  virtual ~Renderer() override;

  /**
   * @brief Clear calls upon the renderer to clear the screen and set the render color to black.
   */
  void clear() override;

  /**
   * @brief Update calls upon the renderer to present the screen.
   */
  void update() override;

  /**
   * @brief RenderWidget calls upon the renderer to render the passed widget.
   * @param widget The widget to be rendered.
   */
  void renderWidget(Widget &widget) override;

private:
  /// The SDL renderer to member
  SDL_Renderer *renderer_;
};
}  // namespace sdl_interface
