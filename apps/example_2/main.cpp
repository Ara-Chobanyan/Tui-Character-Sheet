#include <ftxui/dom/node.hpp>
#include <iostream>
#include <memory>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>

int main()
{
  using namespace ftxui;

  Element document{ hbox({ text("left") | border,
    text("middle") | border | flex,
    text("right") | border }) };

  auto screen{ Screen::Create(Dimension::Full(), Dimension::Fit(document)) };
  Render(screen, document);


  // Control over a specific pixel
  // auto screen {Screen::Create(Dimension::Fixed(32),Dimension::Fixed(10))};

  // auto& pixel{screen.PixelAt(9, 9)};
  // pixel.character = U'A';
  // pixel.bold = true;
  // pixel.foreground_color = Color::Blue;

  screen.Print();

  return 0;
}
