# SPDX-FileCopyrightText: Copyright 2023 Mikhail Svetkin
# SPDX-License-Identifier: MIT

include_guard(GLOBAL)

include(GNUInstallDirs)

add_library(shapes INTERFACE)
add_library(shapes::shapes ALIAS shapes)
install(TARGETS shapes EXPORT shapes-targets)

export(EXPORT shapes-targets NAMESPACE shapes::)
configure_file("cmake/shapes-config.cmake" "." COPYONLY)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  shapes-config-version.cmake COMPATIBILITY SameMajorVersion
)

install(
  EXPORT shapes-targets
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/shapes
  NAMESPACE shapes::
)

install(
  FILES cmake/shapes-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/shapes-config-version.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/shapes
)

