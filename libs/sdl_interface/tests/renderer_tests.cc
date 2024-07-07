#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "sdl_interface/renderer.h"

namespace {
class MockWidget : public sdl_interface::Widget {
public:
  MOCK_METHOD(void, update, (sdl_interface::RendererBase &), (override));
  MOCK_METHOD(void, draw, (SDL_Renderer *), (const, override));
  MOCK_METHOD(bool, contains, (const int, const int), (const, override));
};
}  // namespace

// Example test using MockWidget
TEST(RendererTest, GivenRenderer_WhenRenderingWidget_ThenDrawIsCalled) {
  // Arrange
  MockWidget mockWidget;
  SDL_Window *dummyWindow = nullptr;  // or use a mock SDL_Window if needed
  sdl_interface::Renderer renderer(dummyWindow);

  // Expect draw to be called once
  EXPECT_CALL(mockWidget, draw(testing::_)).Times(1);

  // Act
  renderer.renderWidget(mockWidget);
}
