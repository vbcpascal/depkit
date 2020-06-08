# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.15)

project ("depkit")

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS "-fsanitize=address")

set(Z3_DIR "3rd-party/z3/build")

# find package Z3
find_package(Z3 REQUIRED CONFIG)

message(STATUS "Z3_FOUND: ${Z3_FOUND}")
message(STATUS "Found Z3 ${Z3_VERSION_STRING}")
message(STATUS "Z3_DIR: ${Z3_DIR}")

# find package docopt
find_package(docopt REQUIRED CONFIG)

# source files
file(GLOB SRC "*.hpp" "*.h" "*.cpp")
add_executable(depkit ${SRC})

target_include_directories(depkit PRIVATE ${DOCOPT_INCLUDE_DIRS})
target_include_directories(depkit PRIVATE ${Z3_CXX_INCLUDE_DIRS})
target_include_directories(depkit PRIVATE "/Users/guanzhichao/Softwares/reflex/include")
target_link_libraries(depkit PRIVATE docopt)
target_link_libraries(depkit PRIVATE ${Z3_LIBRARIES} "/Users/guanzhichao/Softwares/reflex/lib/libreflex.a")

if ("${CMAKE_SYSTEM_NAME}" MATCHES "[Ww]indows")
  # On Windows we need to copy the Z3 libraries
  # into the same directory as the executable
  # so that they can be found.
  foreach (z3_lib ${Z3_LIBRARIES})
    message(STATUS "Adding copy rule for ${z3_lib}")
    add_custom_command(TARGET depkit
      POST_BUILD
      COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:${z3_lib}>
        $<TARGET_FILE_DIR:depkit>
    )
  endforeach()
endif()
