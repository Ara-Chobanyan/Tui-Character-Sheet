add_executable(tuiTestNine main.cpp)
target_compile_features(tuiTestNine PRIVATE cxx_std_20)
target_link_libraries(
  tuiTestNine
  PRIVATE colorInfo
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
