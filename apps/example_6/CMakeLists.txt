add_executable(tuiTestSix main.cpp)
target_compile_features(tuiTestSix PRIVATE cxx_std_20)
target_link_libraries(
  tuiTestSix
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
