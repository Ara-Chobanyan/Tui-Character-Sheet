add_executable(tuiTestFour main.cpp)
target_compile_features(tuiTestFour PRIVATE cxx_std_20)
target_link_libraries(
  tuiTestFour
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
