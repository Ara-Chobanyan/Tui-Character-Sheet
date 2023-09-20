#include <ftxui/dom/node.hpp>
#include <iostream>
#include <memory>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>

int main()
{
  using namespace ftxui;

  Element document{ vbox({ text("The Window") | bold | color(Color::Blue),
    gauge(0.5),
    text("the foot") }) };

  // Adding borders
  document = border(document);

  document = document | border;

  document |= border;


  auto screen{ Screen::Create(Dimension::Full(), Dimension::Fit(document)) };
  Render(screen, document);
  screen.Print();


  return 0;
}
