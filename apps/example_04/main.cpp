#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/box.hpp>

using namespace std::chrono_literals;
int main()
{
  using namespace ftxui;
  std::string p{
    R"(In probability theory and statistics, Bayes' theorem (alternatively Bayes' law or Bayes' rule) describes the probability of an event, based on prior knowledge of conditions that might be related to the event. For example, if cancer is related to age, then, using Bayes' theorem, a person's age can be used to more accurately assess the probability that they have cancer, compared to the assessment of the probability of cancer made without knowledge of the person's age. One of the many applications of Bayes' theorem is Bayesian inference, a particular approach to statistical inference. When applied, the probabilities involved in Bayes' theorem may have different probability interpretations. With the Bayesian probability interpretation the theorem expresses how a subjective degree of belief should rationally change to account for availability of related evidence. Bayesian inference is fundamental to Bayesian statistics.)"
  };

  std::string reset_position;
  while (true) {
    auto document{ vbox({
                     hflow(paragraph(p)),
                     separator(),
                     hflow(paragraph(p)),
                     separator(),
                     hbox({
                       hflow(paragraph(p)),
                       separator(),
                       hflow(paragraph(p)),
                     }),
                   })
                   | border };

    document = { vbox(filler(), document) };

    auto screen{ Screen::Create(Dimension::Full()) };
    Render(screen, document);
    std::cout << reset_position;
    screen.Print();
    reset_position = screen.ResetPosition();

    std::this_thread::sleep_for(0.01s);
  }

  return 0;
}
