# SPDX-FileCopyrightText: Copyright 2023 Mikhail Svetkin
# SPDX-License-Identifier: MIT

include_guard(GLOBAL)

include(set_shapes_target_properties)

# sets all nessary default things
function(add_shapes_executable executable_name)
  set(executable_target shapes-${executable_name})

  add_executable(${executable_target} ${ARGN})
  set_shapes_target_properties(${executable_target} PRIVATE)

  if (TARGET shapes)
    install(TARGETS ${executable_target} EXPORT shapes-targets)
  endif()

  set(shapes_executable_target
      ${executable_target}
      PARENT_SCOPE
  )
endfunction()
