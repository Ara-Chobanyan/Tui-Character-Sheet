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

  // std::string firstName;
  // std::string lastName;
  // std::string password;

  // Component inputFirstName{ Input(&firstName, "first name") };
  // Component inputLastName{ Input(&lastName, "last name") };

  // InputOption passwordOptions;
  // passwordOptions.password = true;
  // Component inputPassword{ Input(&password, "password", passwordOptions) };

  // auto component{ Container::Vertical(
  //   { inputFirstName, inputLastName, inputPassword }) };

  // auto renderer{ Renderer(component, [&] {
  //   return vbox({ text("Hello " + firstName + " " + lastName),
  //            separator(),
  //            hbox(text(" First Name : "), inputFirstName->Render()),
  //            hbox(text(" Last Name : "), inputLastName->Render()),
  //            hbox(text(" Password : "), inputPassword->Render()) })
  //          | border;
  // }) };

  // auto screen{ ScreenInteractive::TerminalOutput() };
  // screen.Loop(renderer);


  std::vector<std::string> input_entries(6);
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

  // str
  // dex
  // con
  // int
  // wis
  // cha

  input_str.on_enter = [&] {
    input_entries.at(0) = input_add_content_str;
    input_add_content_str = "";
  };

  input_dex.on_enter = [&] {
    input_entries.at(1) = input_add_content_dex;
    input_add_content_dex = "";
  };

  input_con.on_enter = [&] {
    input_entries.at(2) = input_add_content_con;
    input_add_content_con = "";
  };

  input_int.on_enter = [&] {
    input_entries.at(3) = input_add_content_int;
    input_add_content_int = "";
  };

  input_wis.on_enter = [&] {
    input_entries.at(4) = input_add_content_wis;
    input_add_content_wis = "";
  };

  input_cha.on_enter = [&] {
    input_entries.at(5) = input_add_content_cha;
    input_add_content_cha = input_add_content_cha;
  };

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
    auto input_win{ window(text("Input"),
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
