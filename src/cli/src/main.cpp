// SPDX-FileCopyrightText: Copyright 2023 Mikhail Svetkin
// SPDX-License-Identifier: MIT

#include "shapes/core/shape.hpp"

#include <fmt/core.h>
#include <range/v3/algorithm/for_each.hpp>

struct Rectangle {
  std::size_t width;
  std::size_t height;
};

namespace shapes::opengl {

void draw(const Rectangle &rectangle) {
  fmt::print("opengl::draw rectangle: {}, {}\n", rectangle.width, rectangle.height);
}

} // namespace shapes::opengl

namespace shapes::raster {

void draw(const Rectangle &rectangle) {
  fmt::print("raster::draw rectangle: {}, {}\n", rectangle.width, rectangle.height);
}

} // namespace shapes::raster

int main(int /*argc*/, char * /*argv*/ []) {
  using namespace shapes::core;

  const auto shapes = [] {
    std::vector<Shape> shapes;
    shapes.emplace_back(Rectangle{10, 20});
    return shapes;
  }();

  // The goal is to use two or more backend simultaneously (in one file)
  // without creating another vector of shapes
  // ranges::for_each(shapes, shapes::raster::draw);
  // ranges::for_each(shapes, shapes::opengl::draw);

  return 0;
}
