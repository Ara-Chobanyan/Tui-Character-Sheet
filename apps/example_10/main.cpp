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


  std::vector<std::string> input_entries;
  int input_selected{ 0 };
  Component input{ Menu(&input_entries, &input_selected) };

  auto input_option{ InputOption() };
  std::string input_add_content;
  input_option.on_enter = [&] {
    input_entries.push_back(input_add_content);
    input_add_content = "";
  };

  Component input_add{ Input(&input_add_content, "input files", input_option) };


  auto compiler_component{ Container::Horizontal({ Container::Vertical({
    Container::Horizontal({ input_add, input }),
  }) }) };


  auto render_command{ [&] {
    Elements line;


    for (auto& it : input_entries) {
      line.push_back(text(" " + it) | color(Color::RedLight));
    }
    return line;
  } };

  auto compiler_renderer{ Renderer(compiler_component, [&] {
    auto input_win{ window(text("Input"),
      hbox({ vbox({ hbox({
                      text("Add: "),
                      input_add->Render(),
                    }) | size(WIDTH, EQUAL, 20)
                      | size(HEIGHT, EQUAL, 1),
               filler() }),
        separator(),
        input->Render() | vscroll_indicator | frame | size(HEIGHT, EQUAL, 3)
          | flex })) };


    return vbox({ hbox({ vbox({
                           input_win | size(WIDTH, EQUAL, 60),
                         }),
                    filler() })
                    | size(HEIGHT, LESS_THAN, 8),
             hflow(render_command()) | flex_grow })
           | flex_grow;
  }) };

  auto screen{ ScreenInteractive::TerminalOutput() };
  screen.Loop(compiler_renderer);

  return 0;
}
