add_executable(tuiTest1 main.cpp)
target_compile_features(tuiTest1 PRIVATE cxx_std_20)
target_link_libraries(
  tuiTest1
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
