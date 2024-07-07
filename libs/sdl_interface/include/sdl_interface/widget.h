/**
 * @file  widget.h
 * @brief This file provides and abstract interface for all widgets.
 * @date 07/06/2024
 */

#pragma once
#include <memory>

#include "sdl_interface/renderer.h"

namespace sdl_interface {

/// Forward declaration for the RendererBase class
/// The RendererBase will be an abstract class that will provide the interface for all renderers.
class RendererBase;

/**
 * @class Widget
 * @brief This class is a Widget type which can be used to render a widget to the screen.
 *        The key features of this class are:
 *          1. Provides a minimal abstract interface to render a widget to the screen.

 */
class Widget {
public:
  /**
   * @brief Virtual destructor for the Widget class.
   */
  virtual ~Widget() = default;

  /**
   * @brief This is the main entry point for drawing this widget to the screen.
   *        The widget will call upon the renderer to draw this Widget.
   */
  virtual void update(RendererBase &renderer) = 0;

  /**
   * @brief This method will be called by the renderer to draw in the provided SDL renderer.
   *
   * @param renderer The SDL renderer to draw to.
   */
  virtual void draw(SDL_Renderer *renderer) const = 0;

  /**
   * @brief This method will be called to check if the widget contains the given point.
   *
   * @param x The x position of the point.
   * @param y The y position of the point.
   * @return true if the point is within the widget, false otherwise.
   */
  virtual bool contains(const int x, const int y) const = 0;
};
}  // namespace sdl_interface
