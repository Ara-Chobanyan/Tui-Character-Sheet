add_executable(tuiTestTen main.cpp attribute.cpp)
target_compile_features(tuiTestTen PRIVATE cxx_std_20)
target_link_libraries(
  tuiTestTen 
  PRIVATE colorInfo
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)

