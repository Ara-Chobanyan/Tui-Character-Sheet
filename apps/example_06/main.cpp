#include <chrono>
#include <cmath>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

#include <ftxui/dom/node.hpp>
#include <ftxui/screen/color.hpp>

class Graph
{
public:
  std::vector<int> operator()(int width, int height) const
  {
    std::vector<int> output(width);

    for (int i{ 0 }; i < width; ++i) {
      float v{ 0 };
      v += 0.1f * std::sin((i + shift) * 0.1f);
      v += 0.2f * std::sin((i + shift + 10) * 0.15f);
      v += 0.1f * std::sin((i + shift) * 0.03f);
      v *= height;
      v += 0.5f * height;
      output[i] = static_cast<int>(v);
    }
    return output;
  }

  int shift{ 0 };
};

std::vector<int> triangle(int width, int height)
{
  std::vector<int> output(width);
  for (int i{ 0 }; i < width; ++i) { output[i] = i % (height - 4) + 2; }
  return output;
}


int main()
{
  using namespace ftxui;
  using namespace std::chrono_literals;

  Graph my_graph;
  std::string reset_position;

  for (int i{ 0 };; ++i) {
    // clang-format off
    auto document{ hbox
      ({
        vbox({
            graph(std::ref(my_graph)),
            separator(),
            graph(triangle) | inverted,
        }) | flex,
        separator(),
        vbox({
            graph(std::ref(my_graph)) | color(Color::BlueLight),
            separator(),
            graph(std::ref(my_graph)) | color(Color::RedLight),
            separator(),
            graph(std::ref(my_graph)) | color(Color::YellowLight),
        }) | flex,
    })};
    // clang-format on


    document |= border;

    const int min_width{ 40 };
    document |= size(HEIGHT, GREATER_THAN, min_width);

    auto screen{ Screen::Create(Dimension::Full(), Dimension::Fit(document)) };
    Render(screen, document);
    std::cout << reset_position;
    screen.Print();
    reset_position = screen.ResetPosition();

    const auto sleep_time{ 0.03s };
    std::this_thread::sleep_for(sleep_time);
    my_graph.shift++;
  }


  return 0;
}
