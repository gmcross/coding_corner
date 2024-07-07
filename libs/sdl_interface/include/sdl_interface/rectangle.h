/**
 * @file rectangle.h
 * @brief This file provides a basic rectangle widget that can be rendered to the screen.
 * @date 07/06/2024
 */

#pragma once

#include <SDL2/SDL.h>

#include "sdl_interface/widget.h"

namespace sdl_interface {

/**
 * @class RendererBase
 * @brief This class is a Widget type which can be used to render a rectangle to the screen.
 *        The key features of this class are:
 *          1. Provides a minimal interface to render a rectangle to the screen.
 */
class Rectangle : public Widget {
public:
  /**
   * @brief Constructor for the Rectangle class.
   *
   * @param x The x position of the rectangle.
   * @param y The y position of the rectangle.
   * @param width The width of the rectangle.
   * @param height The height of the rectangle.
   */
  Rectangle(const int x, const int y, const int width, const int height);

  /**
   * @brief Method to set the position of the rectangle after construction.
   *
   * @param x The x position of the rectangle.
   * @param y The y position of the rectangle.
   */
  void setPosition(const int x, const int y);

  /**
   * @brief This is the main entry point for drawing this widget to the screen.
   *        The widget will call upon the renderer to draw this Widget.
   */
  void update(RendererBase &renderer) override;

  /**
   * @brief This method will be called by the renderer to draw in the provided SDL renderer.
   *
   * @param renderer The SDL renderer to draw to.
   */
  void draw(SDL_Renderer *renderer) const override;

  /**
   * @brief This method will be called to check if the rectangle contains the given point.
   *
   * @param x The x position of the point.
   * @param y The y position of the point.
   * @return true if the point is within the rectangle, false otherwise.
   */
  bool contains(const int x, const int y) const override;

private:
  /// The SDL rectangle to be rendered.
  SDL_Rect rect_;
};
}  // namespace sdl_interface
