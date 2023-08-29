#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>

int main()
{
  using namespace ftxui;

  auto summary{ [&] {
    auto content = vbox({
      // clang-format off
        hbox({text(L"- done:   "), text(L"3") | bold}) | color(Color::Green),
        hbox({text(L"- active: "), text(L"2") | bold}) | color(Color::RedLight),
        hbox({text(L"- queue:  "), text(L"9") | bold}) | color(Color::Red),
      });
    // clang-format on
    return window(text(L" Summary"), content);
  } };

  auto document{ vbox({ hbox({ summary(), summary(), summary() | flex }),
    summary(),
    summary() }) };

  document = { document | size(WIDTH, LESS_THAN, 80) };

  auto screen{ Screen::Create(Dimension::Full(), Dimension::Fit(document)) };
  Render(screen, document);

  screen.Print();

  return 0;
}
