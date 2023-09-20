# SPDX-FileCopyrightText: Copyright 2023 Mikhail Svetkin
# SPDX-License-Identifier: MIT

add_shapes_executable(cli)

target_sources(${shapes_executable_target} PRIVATE src/main.cpp)

target_link_libraries(${shapes_executable_target}
  PRIVATE
    shapes::core
)
