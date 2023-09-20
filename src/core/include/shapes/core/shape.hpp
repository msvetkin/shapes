// SPDX-FileCopyrightText: Copyright 2023 Mikhail Svetkin
// SPDX-License-Identifier: MIT

#pragma once

#include "shapes/core/export.hpp"

#include <fmt/core.h>

#include <string>
#include <utility>
#include <memory>

namespace shapes::core {

class SHAPES_CORE_EXPORT Shape {
  struct Concept {
    virtual ~Concept() = default;

    virtual void do_draw() const = 0;
    virtual std::unique_ptr<Concept> clone() const = 0;
  };

  template<typename T>
  struct Model : Concept {
    explicit Model(T shape)
      : shape_(std::move(shape)) {

    }

    void do_draw() const override {
      fmt::print("do_draw, {}\n", __PRETTY_FUNCTION__);
      draw(shape_);
    }

    std::unique_ptr<Concept> clone() const override {
      return std::make_unique<Model<T>>(*this);
    }

    T shape_;
  };

  friend void draw(const Shape &shape);

 public:
  template<typename T>
  explicit Shape(T shape)
    : pimpl_(std::make_unique<Model<T>>(std::move(shape))) {
    fmt::print("Shape: {}\n", __PRETTY_FUNCTION__);
  }

  Shape(const Shape &other);
  Shape& operator=(const Shape &other);

  Shape(Shape &&other) = default;
  Shape& operator=(Shape &&other) = default;

 private:
  std::unique_ptr<Concept> pimpl_;
};

SHAPES_CORE_EXPORT void draw(const Shape &shape);

} // namespace shapes::core
