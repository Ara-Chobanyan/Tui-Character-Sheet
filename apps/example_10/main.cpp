#include <ftxui/component/captured_mouse.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/util/ref.hpp>
#include <vector>
#include <string>


int main(int argc, char* argv[])
{
  using namespace ftxui;

  auto modFunc{ [&](const std::string& attribute) -> std::string {
    int attributeInt{ (std::stoi(attribute) - 10) / 2 };
    return std::to_string(attributeInt);
  } };

  std::vector<std::string> input_entries(6, "");
  int input_selected{ 0 };

  // right half of the vbox
  Component input{ Menu(&input_entries, &input_selected) };

  std::string input_add_content_str;
  std::string input_add_content_dex;
  std::string input_add_content_con;
  std::string input_add_content_int;
  std::string input_add_content_wis;
  std::string input_add_content_cha;

  auto input_str{ InputOption() };
  auto input_dex{ InputOption() };
  auto input_wis{ InputOption() };
  auto input_int{ InputOption() };
  auto input_cha{ InputOption() };
  auto input_con{ InputOption() };

  auto onEenterEvent{ [&](std::string& input_content, int index) -> void {
    auto temp = input_content;
    input_entries.at(index) = modFunc(input_content);
    input_content = temp;
  } };

  input_str.on_enter = [&] { onEenterEvent(input_add_content_str, 0); };
  input_dex.on_enter = [&] { onEenterEvent(input_add_content_dex, 1); };
  input_con.on_enter = [&] { onEenterEvent(input_add_content_con, 2); };
  input_int.on_enter = [&] { onEenterEvent(input_add_content_int, 3); };
  input_wis.on_enter = [&] { onEenterEvent(input_add_content_wis, 4); };
  input_cha.on_enter = [&] { onEenterEvent(input_add_content_cha, 5); };


  // input_str.on_enter = [&] {
  //   auto tempStr = input_add_content_str;
  //   input_entries.at(0) = modFunc(input_add_content_str);
  //   input_add_content_str = tempStr;
  // };

  // input_dex.on_enter = [&] {
  //   auto tempDex = input_add_content_dex;
  //   input_entries.at(1) = modFunc(input_add_content_dex);
  //   input_add_content_dex = tempDex;
  // };

  // input_con.on_enter = [&] {
  //   auto tempCon = input_add_content_con;
  //   input_entries.at(2) = modFunc(input_add_content_con);
  //   input_add_content_con = tempCon;
  // };

  // input_int.on_enter = [&] {
  //   auto tempInt = input_add_content_int;
  //   input_entries.at(3) = modFunc(input_add_content_int);
  //   input_add_content_int = tempInt;
  // };

  // input_wis.on_enter = [&] {
  //   auto tempWis = input_add_content_wis;
  //   input_entries.at(4) = modFunc(input_add_content_wis);
  //   input_add_content_wis = tempWis;
  // };

  // input_cha.on_enter = [&] {
  //   auto tempCha = input_add_content_cha;
  //   input_entries.at(5) = modFunc(input_add_content_cha);
  //   input_add_content_cha = tempCha;
  // };

  Component input_add_str{ Input(
    &input_add_content_str, "input files", input_str) };
  Component input_add_dex{ Input(
    &input_add_content_dex, "input files", input_dex) };
  Component input_add_wis{ Input(
    &input_add_content_wis, "input files", input_wis) };
  Component input_add_int{ Input(
    &input_add_content_int, "input files", input_int) };
  Component input_add_con{ Input(
    &input_add_content_con, "input files", input_con) };
  Component input_add_cha{ Input(
    &input_add_content_cha, "input files", input_cha) };


  // Alows the use of the inputs.
  auto compiler_component{ Container::Horizontal({ Container::Vertical({
    Container::Horizontal({ input_add_str, input }),
    Container::Horizontal({ input_add_dex, input }),
    Container::Horizontal({ input_add_con, input }),
    Container::Horizontal({ input_add_int, input }),
    Container::Horizontal({ input_add_wis, input }),
    Container::Horizontal({ input_add_cha, input }),
  }) }) };


  auto compiler_renderer{ Renderer(compiler_component, [&] {
    auto input_win{ window(text("Attributes"),
      hbox({ vbox({ hbox({
                      text("Str: "),
                      input_add_str->Render(),
                    }) | size(WIDTH, EQUAL, 20)
                      | size(HEIGHT, EQUAL, 1),
               hbox({
                 text("Dex: "),
                 input_add_dex->Render(),
               }) | size(WIDTH, EQUAL, 20)
                 | size(HEIGHT, EQUAL, 1),
               hbox({
                 text("Con: "),
                 input_add_con->Render(),
               }) | size(WIDTH, EQUAL, 20)
                 | size(HEIGHT, EQUAL, 1),
               hbox({
                 text("Int: "),
                 input_add_int->Render(),
               }) | size(WIDTH, EQUAL, 20)
                 | size(HEIGHT, EQUAL, 1),
               hbox({
                 text("Wis: "),
                 input_add_wis->Render(),
               }) | size(WIDTH, EQUAL, 20)
                 | size(HEIGHT, EQUAL, 1),
               hbox({
                 text("Cha: "),
                 input_add_cha->Render(),
               }) | size(WIDTH, EQUAL, 20)
                 | size(HEIGHT, EQUAL, 1),
               filler() }),
        separator(),
        input->Render() | vscroll_indicator | frame | size(HEIGHT, EQUAL, 4)
          | flex })) };


    return vbox({
             hbox({ vbox({
                      input_win | size(WIDTH, EQUAL, 60),
                    }),
               filler() })
               | size(HEIGHT, LESS_THAN, 8),
           })
           | flex_grow;
  }) };

  auto screen{ ScreenInteractive::TerminalOutput() };
  screen.Loop(compiler_renderer);

  return 0;
}
