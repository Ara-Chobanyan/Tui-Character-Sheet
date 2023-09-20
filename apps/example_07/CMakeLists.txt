add_executable(tuiTest7 main.cpp)
target_compile_features(tuiTest7 PRIVATE cxx_std_20)
target_link_libraries(
  tuiTest7
  PRIVATE colorInfo
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
