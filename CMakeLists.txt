cmake_minimum_required(VERSION 3.14...3.26)

project(
  practiceTUI
  VERSION 0.0.1
  LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
  GIT_TAG v4.1.1)
FetchContent_MakeAvailable(ftxui)
add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory(apps)
add_subdirectory(include)
