
add_executable(tuiTestOne main.cpp)
target_compile_features(tuiTestOne PRIVATE cxx_std_20)
target_link_libraries(
  tuiTestOne
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
