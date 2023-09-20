#include <cmath>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/component/mouse.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/canvas.hpp>
#include <ftxui/screen/color.hpp>

int main()
{
  using namespace ftxui;

  int mouse_x{ 0 };
  int mouse_y{ 0 };

  auto renderer_line_braille{ Renderer([&] {
    auto c{ Canvas(100, 100) };
    c.DrawText(0, 0, "Several lines (braille)");
    c.DrawPointLine(mouse_x, mouse_y, 80, 10, Color::Red);
    c.DrawPointLine(80, 10, 80, 40, Color::Blue);
    c.DrawPointLine(80, 40, mouse_x, mouse_y, Color::Green);
    return canvas(std::move(c));
  }) };

  auto renderer_line_block{ Renderer([&] {
    auto c{ Canvas{ 100, 100 } };
    c.DrawText(0, 0, "Several lines (block)");
    c.DrawBlockLine(mouse_x, mouse_y, 80, 10, Color::Red);
    c.DrawBlockLine(80, 10, 80, 40, Color::Blue);
    c.DrawBlockLine(80, 40, mouse_x, mouse_y, Color::Green);
    return canvas(std::move(c));
  }) };

  auto renderer_circle_braille{ Renderer([&] {
    auto c{ Canvas{ 100, 100 } };
    c.DrawText(0, 0, "A circle (braille)");
    c.DrawPointCircle(mouse_x, mouse_y, 30);
    return canvas(std::move(c));
  }) };

  auto renderer_circle_block{ Renderer([&] {
    auto c{ Canvas{ 100, 100 } };
    c.DrawText(0, 0, "A circle (block)");
    c.DrawBlockCircle(mouse_x, mouse_y, 30);
    return canvas(std::move(c));
  }) };

  auto renderer_circle_filled_braille{ Renderer([&] {
    auto c{ Canvas{ 100, 100 } };
    c.DrawText(0, 0, "A circle filled (braille)");
    c.DrawPointCircleFilled(mouse_x, mouse_y, 30);
    return canvas(std::move(c));
  }) };

  auto renderer_circle_filled_block{ Renderer([&] {
    auto c{ Canvas{ 100, 100 } };
    c.DrawText(0, 0, "A circle filled (block)");
    c.DrawBlockCircleFilled(mouse_x, mouse_y, 30);
    return canvas(std::move(c));
  }) };

  auto renderer_elipse_braille{ Renderer([&] {
    auto c{ Canvas{ 100, 100 } };
    c.DrawText(0, 0, "An ellipse (braille)");
    c.DrawPointEllipse(mouse_x / 2, mouse_y / 2, mouse_x / 2, mouse_y / 2);
    return canvas(std::move(c));
  }) };

  auto renderer_elipse_block{ Renderer([&] {
    auto c{ Canvas{ 100, 100 } };
    c.DrawText(0, 0, "An ellipse (block)");
    c.DrawBlockEllipse(mouse_x / 2, mouse_y / 2, mouse_x / 2, mouse_y / 2);
    return canvas(std::move(c));
  }) };

  auto renderer_elipse_filled_braille{ Renderer([&] {
    auto c{ Canvas{ 100, 100 } };
    c.DrawText(0, 0, "A filled ellipse (braille)");
    c.DrawPointEllipseFilled(
      mouse_x / 2, mouse_y / 2, mouse_x / 2, mouse_y / 2);
    return canvas(std::move(c));
  }) };

  auto renderer_elipse_filled_block{ Renderer([&] {
    auto c{ Canvas{ 100, 100 } };
    c.DrawText(0, 0, "A filled ellipse (block)");
    c.DrawBlockEllipseFilled(
      mouse_x / 2, mouse_y / 2, mouse_x / 2, mouse_y / 2);
    return canvas(std::move(c));
  }) };

  auto renderer_text{ Renderer([&] {
    auto c{ Canvas(100, 100) };
    c.DrawText(0, 0, "A piece of text");
    c.DrawText(
      mouse_x, mouse_y, "This is a piece of text with effects", [](Pixel& p) {
        p.foreground_color = Color::Red;
        p.underlined = true;
        p.bold = true;
      });
    return canvas(std::move(c));
  }) };

  auto renderer_plot_1{ Renderer([&] {
    auto c{ Canvas{ 100, 100 } };
    c.DrawText(0, 0, "A graph");

    std::vector<int> ys(100);
    for (int x{ 0 }; x < 100; x++) {
      float dx{ static_cast<float>(x - mouse_x) };
      float dy{ 50.f };
      ys[x] = static_cast<int>((dy + 20 * 0.14) + 10 * std::sin(dx * 0.42));
    }
    for (int x{ 1 }; x < 99; x++) {
      c.DrawPointLine(x, ys[x], x + 1, ys[x + 1]);
    }
    return canvas(std::move(c));
  }) };

  auto renderer_plot_2{ Renderer([&] {
    auto c{ Canvas(100, 100) };
    c.DrawText(0, 0, "A symmetrical graph filled");

    std::vector<int> ys(100);
    for (int x{ 0 }; x < 100; x++) {
      ys[x] = static_cast<int>(30 + 10 * std::cos(x * 0.2 - mouse_x * 0.05)
                               + 5 * std::sin(x * 0.4)
                               + 5 * std::sin(x * 0.3 - mouse_y * 0.05));
    }

    for (int x{ 0 }; x < 100; x++) {
      c.DrawPointLine(x, 50 + ys[x], x, 50 - ys[x], Color::Red);
    }

    return canvas(std::move(c));
  }) };

  auto renderer_plot_3{ Renderer([&] {
    auto c{ Canvas(100, 100) };
    c.DrawText(0, 0, "A 2D gaussian plot");
    int size{ 15 };

    float my{ (mouse_y - 90) / -5.f };
    float mx{ (mouse_x - 3 * my) / 5.f };
    std::vector<std::vector<float>> ys(size, std::vector<float>(size));
    for (int y{ 0 }; y < size; y++) {
      for (int x{ 0 }; x < size; x++) {
        float dx{ x - mx };
        float dy{ y - my };
        ys[y][x] = -1.5 + 3.0 * std::exp(-0.2f * (dx * dx + dy * dy));
      }
    }
    for (int y{ 0 }; y < size; y++) {
      for (int x{ 0 }; x < size; x++) {
        if (x != 0) {
          c.DrawPointLine(5 * (x - 1) + 3 * (y - 0),
            90 - 5 * (y - 0) - 5 * ys[y][x - 1],
            5 * (x - 0) + 3 * (y - 0),
            90 - 5 * (y - 0) - 5 * ys[y][x]);
        }
        if (y != 0) {
          c.DrawPointLine(5 * (x - 0) + 3 * (y - 1),
            90 - 5 * (y - 1) - 5 * ys[y - 1][x],
            5 * (x - 0) + 3 * (y - 0),
            90 - 5 * (y - 0) - 5 * ys[y][x]);
        }
      }
    }
    return canvas(std::move(c));
  }) };

  int selected_tab{ 12 };
  auto tab{ Container::Tab(
    {
      renderer_line_braille,
      renderer_line_block,
      renderer_circle_braille,
      renderer_circle_block,
      renderer_circle_filled_braille,
      renderer_circle_filled_block,
      renderer_elipse_braille,
      renderer_elipse_block,
      renderer_elipse_filled_braille,
      renderer_elipse_filled_block,

      renderer_plot_1,
      renderer_plot_2,
      renderer_plot_3,

      renderer_text,
    },
    &selected_tab) };

  auto tab_with_mouse{ CatchEvent(tab, [&](Event e) {
    if (e.is_mouse()) {
      mouse_x = (e.mouse().x - 1) * 2;
      mouse_y = (e.mouse().y - 1) * 4;
    }
    return false;
  }) };

  std::vector<std::string> tab_titles{
    "line (braille)",
    "line (block)",
    "circle (braille)",
    "circle (block)",
    "circle filled (braille)",
    "circle filled (block)",
    "ellipse (braille)",
    "ellipse (block)",
    "ellipse filled (braille)",
    "ellipse filled (block)",
    "plot_1 simple",
    "plot_2 filled",
    "plot_3 3D",
    "text",
  };

  // Will need to review to understand it better
  auto tab_toggle{ Menu(&tab_titles, &selected_tab) };

  auto component{ Container::Horizontal({ tab_with_mouse, tab_toggle }) };

  auto component_renderer{ Renderer(component, [&] {
    return hbox({
             tab_with_mouse->Render(),
             separator(),
             tab_toggle->Render(),
           })
           | border;
  }) };

  auto screen{ ScreenInteractive::FitComponent() };
  screen.Loop(component_renderer);


  return 0;
}
