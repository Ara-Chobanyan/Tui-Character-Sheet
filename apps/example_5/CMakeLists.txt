add_executable(tuiTestFive main.cpp)
target_compile_features(tuiTestFive PRIVATE cxx_std_20)
target_link_libraries(
  tuiTestFive
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
