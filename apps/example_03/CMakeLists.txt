add_executable(tuiTest3 main.cpp)
target_compile_features(tuiTest3 PRIVATE cxx_std_20)
target_link_libraries(
  tuiTest3
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
