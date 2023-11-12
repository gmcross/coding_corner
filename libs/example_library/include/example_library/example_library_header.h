#pragma once
#include <iostream>

namespace example_library {
class ExampleClass {
public:
  ExampleClass() = default;
  void printMessage(const std::string &message);
};
}  // namespace example_library
