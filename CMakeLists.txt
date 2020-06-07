# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.15)

project ("TPM")

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
message(STATUS "Z3_DIR: ${Z3_DIR}")

find_package(Z3
  REQUIRED
  CONFIG
)

message(STATUS "Z3_FOUND: ${Z3_FOUND}")
message(STATUS "Found Z3 ${Z3_VERSION_STRING}")
message(STATUS "Z3_DIR: ${Z3_DIR}")

# 包含子项目。
file(GLOB SRC "*.h" "*.cpp")
add_executable(TPM ${SRC})

target_include_directories(TPM PRIVATE ${Z3_CXX_INCLUDE_DIRS})
target_link_libraries(TPM PRIVATE ${Z3_LIBRARIES})

if ("${CMAKE_SYSTEM_NAME}" MATCHES "[Ww]indows")
  # On Windows we need to copy the Z3 libraries
  # into the same directory as the executable
  # so that they can be found.
  foreach (z3_lib ${Z3_LIBRARIES})
    message(STATUS "Adding copy rule for ${z3_lib}")
    add_custom_command(TARGET TPM
      POST_BUILD
      COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:${z3_lib}>
        $<TARGET_FILE_DIR:TPM>
    )
  endforeach()
endif()
