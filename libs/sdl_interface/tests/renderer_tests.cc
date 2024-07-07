#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "sdl_interface/renderer.h"

namespace {
class TestWidget : public sdl_interface::Widget {
public:
  TestWidget() : mouse_x_(0), mouse_y_(0) {}

  void update(sdl_interface::RendererBase &renderer) override {
    renderer.renderWidget(*this);
  }

  void draw(SDL_Renderer *renderer) const override {
    ++draw_count_;
  }

  void onMouseMotion(int x, int y) override {
    mouse_x_ = x;
    mouse_y_ = y;
  }

private:
  mutable int draw_count_ = 0;
  int mouse_x_, mouse_y_;
};
}  // namespace

// Mock class for Renderer
class MockRenderer : public sdl_interface::RendererBase {
public:
  MOCK_METHOD(void, clear, (), (override));
  MOCK_METHOD(void, update, (), (override));
  MOCK_METHOD(void, renderWidget, (sdl_interface::Widget &), (override));
};


TEST(WidgetTest, UpdateCallsRenderWidget) {
  MockRenderer mockRenderer;
  TestWidget widget;

  EXPECT_CALL(mockRenderer, renderWidget(testing::Ref(widget))).Times(1);

  widget.update(mockRenderer);
}
