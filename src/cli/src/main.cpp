// SPDX-FileCopyrightText: Copyright 2023 Mikhail Svetkin
// SPDX-License-Identifier: MIT

#include "shapes/core/shape.hpp"

#include <fmt/core.h>
#include <range/v3/algorithm/for_each.hpp>

struct Rectangle {
  std::size_t width;
  std::size_t height;
};

void draw(const Rectangle &rectangle) {
  fmt::print("draw rectangle: {}, {}\n", rectangle.width, rectangle.height);
}

int main(int /*argc*/, char * /*argv*/ []) {
  using namespace shapes::core;

  std::vector<Shape> shapes;
  shapes.emplace_back(Rectangle{10, 20});


  ranges::for_each(shapes, shapes::core::draw);
  return 0;
}
