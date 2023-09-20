add_executable(tuiTest4 main.cpp)
target_compile_features(tuiTest4 PRIVATE cxx_std_20)
target_link_libraries(
  tuiTest4
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
