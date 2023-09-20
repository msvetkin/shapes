// SPDX-FileCopyrightText: Copyright 2023 Mikhail Svetkin
// SPDX-License-Identifier: MIT

#include "shapes/core/shape.hpp"

#include <fmt/core.h>

namespace shapes::core {

void draw(const Shape &shape) {
  fmt::print("shapes::core::draw\n");
  shape.pimpl_->do_draw();
}

Shape::Shape(const Shape &other)
 : pimpl_(other.pimpl_->clone()) {
}

Shape& Shape::operator=(const Shape &other) {
  other.pimpl_->clone().swap(pimpl_);
  return *this;
}

} // namespace shapes::core
