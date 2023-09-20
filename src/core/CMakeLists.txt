# SPDX-FileCopyrightText: Copyright 2023 Mikhail Svetkin
# SPDX-License-Identifier: MIT

add_shapes_module(core)

target_sources(${shapes_module_target} PRIVATE
  include/shapes/core/shape.hpp
  src/shape.cpp)
