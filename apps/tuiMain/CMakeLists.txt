add_executable(tuiMain main.cpp)
target_compile_features(tuiMain PRIVATE cxx_std_20)
target_link_libraries(
  tuiMain
  PRIVATE colorInfo
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)

