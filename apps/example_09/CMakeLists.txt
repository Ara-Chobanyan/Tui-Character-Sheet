add_executable(tuiTest9 main.cpp attribute.cpp)
target_compile_features(tuiTest9 PRIVATE cxx_std_20)
target_link_libraries(
  tuiTest9
  PRIVATE colorInfo
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)

