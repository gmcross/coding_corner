#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "sdl_interface/rectangle.h"

namespace {
class MockRenderer : public sdl_interface::Renderer {
public:
  // Match the constructor of the real Renderer
  MockRenderer(SDL_Window *window) : Renderer(window) {}

  MOCK_METHOD(void, clear, (), (override));
  MOCK_METHOD(void, update, (), (override));
  MOCK_METHOD(void, renderWidget, (sdl_interface::Widget &), (override));
};
}  // namespace

TEST(RectangleTest, GivenRectangle_WhenDrawing_ThenDrawIsCalled) {
  // Arrange
  SDL_Window *dummyWindow = nullptr;  // or use a mock SDL_Window if needed
  MockRenderer mockRenderer(dummyWindow);
  sdl_interface::Rectangle rectangle(0, 0, 10, 10);

  // Expect draw to be called once
  EXPECT_CALL(mockRenderer, renderWidget(testing::_)).Times(1);

  // Act
  rectangle.update(mockRenderer);
}

TEST(RectangleTest, GivenRectangle_Contains_WhenPointInside) {
  sdl_interface::Rectangle rectangle(0, 0, 10, 10);

  // Point inside the rectangle
  EXPECT_TRUE(rectangle.contains(5, 5));

  // Point outside the rectangle
  EXPECT_FALSE(rectangle.contains(5, 11));
  EXPECT_FALSE(rectangle.contains(11, 5));
  EXPECT_FALSE(rectangle.contains(-1, 5));
  EXPECT_FALSE(rectangle.contains(5, -1));
}
