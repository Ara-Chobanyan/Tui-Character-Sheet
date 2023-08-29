
add_executable(tuiTestThree main.cpp)
target_compile_features(tuiTestThree PRIVATE cxx_std_20)
target_link_libraries(
  tuiTestThree
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
