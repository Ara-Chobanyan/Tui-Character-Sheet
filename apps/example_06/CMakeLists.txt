add_executable(tuiTest6 main.cpp)
target_compile_features(tuiTest6 PRIVATE cxx_std_20)
target_link_libraries(
  tuiTest6
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
