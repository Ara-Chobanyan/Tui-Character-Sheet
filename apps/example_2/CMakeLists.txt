
add_executable(tuiTestTwo main.cpp)
target_compile_features(tuiTestTwo PRIVATE cxx_std_20)
target_link_libraries(
  tuiTestTwo
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
