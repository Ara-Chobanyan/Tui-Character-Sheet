add_executable(tuiTest main.cpp)
target_compile_features(tuiTest PRIVATE cxx_std_20)
target_link_libraries(
  tuiTest
  PRIVATE colorInfo
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
