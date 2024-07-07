/**
 * @file widget_manager.h
 * @brief This file provides a WidgetManager class that can be used to manage multiple widgets.
 * @date 07/06/2024
 */

#pragma once
#include <vector>

#include "sdl_interface/widget.h"

namespace sdl_interface {

/**
 * @class WidgetManager
 * @brief This class will manage multiple widgets and update them when required.
 *        This will also provide event handling for the widgets, such as mouse motion,
 *        calling the appropriate widget's methods. (This may be moved else where)
 *
 *        The key features of this class are:
 *          1. Provides an interface for managing multiple widgets.
 *
 */
class WidgetManager {
public:
  /**
   * @brief Method to add a widget to the manager.
   *
   * @param widget The widget to be added.
   */
  void addWidget(const std::shared_ptr<Widget> widget) { widgets_.push_back(std::move(widget)); }

  /**
   * @brief Method to update all the widgets in the manager.
   *        This will call the update method of each widget with the provided renderer to display the widgets.
   *
   * @param renderer The renderer to be used to update the widgets.
   */
  void update(const std::shared_ptr<RendererBase> &renderer) {
    for (auto &widget : widgets_) {
      widget->update(*renderer);
    }
  }

  void onMouseMotion(int x, int y) {
    for (auto &widget : widgets_) {
      widget->contains(x, y);
    }
  }

private:
  /// Vector to store the widgets.
  std::vector<std::shared_ptr<Widget>> widgets_;
};

}  // namespace sdl_interface
