cmake_minimum_required(VERSION 3.10)
project(system)
set(CMAKE_C_STANDARD 11)

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -std=gnu99 -g")
# ---------------------------------------------------------------------------
# files
# ---------------------------------------------------------------------------
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(GLOB_RECURSE ALL_SOURCE_FILES
  "01_linux/*.c"
  "02_file_io/*.c"
  "03_process/*.c"
  "04_thread/*.c"
  "05_ipc/*/*.c"
  "06_mutex/*.c"
  "07_signal/*.c"
  "08_socket/*.c"
  "09_epoll/*.c"
  "10_project/*.c"
  "11_algorithm/*.c"
  )

# ---------------------------------------------------------------------------
# executable
# ---------------------------------------------------------------------------
# add_executable(uqzip ${ALL_SOURCE_FILES})
# target_compile_options(uqzip PRIVATE -Wall -Wextra -pedantic -std=gnu99 -g)
# ---------------------------------------------------------------------------
# clang-format
# ---------------------------------------------------------------------------

# fix format, you should make sure the ${ALL_SOURCE_FILES} is not empty and
# valid -i indicate inplace update
add_custom_target(
  format
  COMMAND clang-format --style=file -i ${ALL_SOURCE_FILES}
  VERBATIM
)

# ---------------------------------------------------------------------------
# clang-tidy
# ---------------------------------------------------------------------------

find_program(CLANG_TIDY_BIN NAMES "clang-tidy")
if(CLANG_TIDY_BIN)
  # leanstore
  add_custom_target(
    check-tidy
    COMMAND ${CLANG_TIDY_BIN} -p=${CMAKE_BINARY_DIR}
            --config-file=${CMAKE_SOURCE_DIR}/.clang-tidy ${ALL_SOURCE_FILES}
    COMMENT "Running Clang-Tidy"
    VERBATIM)
  # myself
  add_custom_target(
    clang-tidy-fix
    COMMAND ${CLANG_TIDY_BIN} --fix --quiet ${ALL_SOURCE_FILES}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running clang-tidy with automatic fix"
    VERBATIM)
endif()
# ---------------------------------------------------------------------------
# cmake-format
# ---------------------------------------------------------------------------
find_program(CMAKE_FORMAT_EXECUTABLE cmake-format)
if(CMAKE_FORMAT_EXECUTABLE)
  add_custom_target(
    cformat
    COMMAND ${CMAKE_FORMAT_EXECUTABLE} -i ${CMAKE_SOURCE_DIR}/CMakeLists.txt
    COMMENT "Formatting CMakeLists.txt")
else()
  message(
    WARNING "cmake-format not found. Install it via 'pip install cmake-format'")
endif()
