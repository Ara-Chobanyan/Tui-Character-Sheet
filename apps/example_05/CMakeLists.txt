add_executable(tuiTest5 main.cpp)
target_compile_features(tuiTest5 PRIVATE cxx_std_20)
target_link_libraries(
  tuiTest5
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
