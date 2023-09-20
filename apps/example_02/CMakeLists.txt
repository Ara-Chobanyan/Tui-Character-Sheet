add_executable(tuiTest2 main.cpp)
target_compile_features(tuiTest2 PRIVATE cxx_std_20)
target_link_libraries(
  tuiTest2
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
