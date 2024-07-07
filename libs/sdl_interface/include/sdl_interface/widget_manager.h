#pragma once
#include <vector>

#include "sdl_interface/widget.h"
namespace sdl_interface {

class WidgetManager {
public:
  void addWidget(const std::shared_ptr<Widget> widget) { widgets_.push_back(std::move(widget)); }

  void update(const std::shared_ptr<RendererBase> &renderer) {
    for (auto &widget : widgets_) {
      widget->update(*renderer);
    }
  }

  void onMouseMotion(int x, int y) {
    for (auto &widget : widgets_) {
      widget->onMouseMotion(x, y);
    }
  }

private:
  std::vector<std::shared_ptr<Widget>> widgets_;
};

}  // namespace sdl_interface
