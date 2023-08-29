#include <iostream>
#include <vector>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/table.hpp>
#include <chrono>
#include <atomic>
#include <thread>


int main()
{
  using namespace ftxui;
  using namespace std::chrono_literals;

  auto screen{ ScreenInteractive::FitComponent() };
  int shift{ 0 };

  std::cout << '\n';

  auto summary{ Renderer([&] {
    auto name{ vbox({ hbox(text("Name: Ara")) | hcenter,
      separator(),
      hbox(text("Class: Wizard")) | hcenter }) };

    auto hitPoints{ vbox({ text("HP") | hcenter,
      hbox({ vbox(text("Current: 19")),
        separator(),
        vbox(text("Max: 19/19")),
        separator(),
        vbox(text("Temp: 0")),
        separator(),
        vbox(text("Non-Lethal: 0")) }) }) };

    auto defenses{ vbox({
      text("Defenses") | hcenter,
      hbox({
        hbox({
          vbox(text("AC: 20")),
          separator(),
          vbox(text("Touch: 15")),
          separator(),
          vbox(text("Flat: 10")),
        }),
        separator(),
        hbox({
          vbox(text("Fort: 10")),
          separator(),
          vbox(text("Reflex: 14")),
          separator(),
          vbox(text("Will: 10")),
        }),
      }),
    }) };

    return hbox({ separator(),
             vbox({ name,
               separator(),
               hitPoints,
               separator(),
               defenses,
               separator() }) })
           | flex;
  }) };

  auto summarySkill{ Renderer([&] {
    auto skillTable{ Table({
      { "Skill ", "Mod ", "Rank " },
      { "Acrobatics ", "1 ", "1 " },
      { "Appraise ", "1 ", "1 " },
      { "Bluff ", "1 ", "1 " },
      { "Diplomacy ", "1 ", "1 " },
      { "Disguise ", "1 ", "1 " },
      { "Fly ", "1 ", "1 " },
    }) };

    skillTable.SelectRow(0).Decorate(bold);
    skillTable.SelectAll().Separator();

    return vbox({ skillTable.Render() });
  }) };


  auto summaryAtri{ Renderer([&] {
    auto attributeTable{ Table({
      { "Abi ", "Total ", "Mod ", "Pen " },
      { "Str ", "Total ", "Mod ", "Pen " },
      { "Dex ", "Total ", "Mod ", "Pen " },
      { "Con ", "Total ", "Mod ", "Pen " },
      { "Int ", "Total ", "Mod ", "Pen " },
      { "Wis ", "Total ", "Mod ", "Pen " },
      { "Cha ", "Total ", "Mod ", "Pen " },
    }) };


    attributeTable.SelectRow(0).Decorate(bold);
    attributeTable.SelectAll().Separator();

    return vbox({ attributeTable.Render() });
  }) };

  int tabIndex{ 0 };

  std::vector<std::string> tabEntries{ "summary", "attributes", "skills" };

  auto tabSelection{ Menu(
    &tabEntries, &tabIndex, MenuOption::HorizontalAnimated()) };

  auto tabContent{ Container::Tab(
    { summary, summaryAtri, summarySkill }, &tabIndex) };

  auto mainContainer{ Container::Vertical({ tabSelection, tabContent }) };

  auto mainRenderer{ Renderer(mainContainer, [&] {
    return vbox({ text("Pathfinder Character Sheet") | bold | hcenter,
      tabSelection->Render(),
      tabContent->Render() | flex });
  }) };

  std::atomic<bool> refreshUiContinue{ true };
  std::thread refreshUi([&] {
    while (refreshUiContinue) {
      std::this_thread::sleep_for(0.05s);

      screen.Post([&] { shift++; });
      screen.Post(Event::Custom);
    }
  });

  screen.Loop(mainRenderer);
  refreshUiContinue = false;
  refreshUi.join();
  std::cout << '\n';
  return 0;
}

// goals
// [x] implement a basic front sheet
// [x] implement a basic tab function
