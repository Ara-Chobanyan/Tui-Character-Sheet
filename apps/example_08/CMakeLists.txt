add_executable(tuiTest8 main.cpp)
target_compile_features(tuiTest8 PRIVATE cxx_std_20)
target_link_libraries(
  tuiTest8
  PRIVATE colorInfo
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
