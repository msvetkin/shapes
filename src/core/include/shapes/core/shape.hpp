// SPDX-FileCopyrightText: Copyright 2023 Mikhail Svetkin
// SPDX-License-Identifier: MIT

#pragma once

#include "shapes/core/export.hpp"

#include <string>

namespace shapes::core {

[[nodiscard]] SHAPES_CORE_EXPORT std::string version() noexcept;

} // namespace shapes::core
