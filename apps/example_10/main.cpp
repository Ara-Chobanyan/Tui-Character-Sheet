#include "attribute.hpp"


// enum class Attributes { str, dex, con, inti, wis, cha };

int main()
{
  // using namespace ftxui;
  // std::string output{ "debug.txt" };
  // std::ofstream outPutFile{ output };

  // auto modFunc{ [&](const std::string& attribute) -> std::string {
  //   int attributeInt{ (std::stoi(attribute) - 10) / 2 };
  //   return std::to_string(attributeInt);
  // } };

  // auto isNumber{ [&](const std::string& s) -> bool {
  //   return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c)
  //   {
  //     return !std::isdigit(c);
  //   }) == s.end();
  // } };

  // std::vector<std::string> inputEntries(6, "");
  // int inputSelected{ 0 };

  // // shows the modifiers of the attributes
  // Component input{ Menu(&inputEntries, &inputSelected) };

  // // holds the whole attribute value
  // std::string strAttribute;
  // std::string dexAttribute;
  // std::string conAttribute;
  // std::string intAttribute;
  // std::string wisAttribute;
  // std::string chaAttribute;

  // std::string strAttributeDamage;
  // std::string dexAttributeDamage;
  // std::string conAttributeDamage;
  // std::string intAttributeDamage;
  // std::string wisAttributeDamage;
  // std::string chaAttributeDamage;

  // std::unordered_map<std::string, std::string> storage{
  //   { "strength", strAttributeDamage },
  //   { "dexterity", dexAttributeDamage },
  //   { "constitution", conAttributeDamage },
  //   { "intelligence", intAttributeDamage },
  //   { "wisdom", wisAttributeDamage },
  //   { "cha", chaAttributeDamage },
  // };

  // // Normal attribute input
  // auto inputStr{ InputOption() };
  // auto inputDex{ InputOption() };
  // auto inputWis{ InputOption() };
  // auto inputInt{ InputOption() };
  // auto inputCha{ InputOption() };
  // auto inputCon{ InputOption() };

  // // damage attribute input
  // auto inputStrDamage{ InputOption() };
  // auto inputDexDamage{ InputOption() };
  // auto inputWisDamage{ InputOption() };
  // auto inputIntDamage{ InputOption() };
  // auto inputChaDamage{ InputOption() };
  // auto inputConDamage{ InputOption() };

  // auto onEnterEvent{ [&](std::string& input_content, int index) -> void {
  //   auto temp = input_content;
  //   inputEntries.at(index) = modFunc(input_content);
  //   input_content = temp;
  // } };

  // auto applyDamage{ [&](std::string& damage,
  //                     std::string& attribute,
  //                     std::string_view keyAttribute,
  //                     int index) -> void {
  //   try {
  //     int attributeVal{ std::stoi(attribute) };
  //     int dmgVal{ std::stoi(damage) };
  //     if (dmgVal < 0) { dmgVal = std::abs(dmgVal); }

  //     if (storage[keyAttribute.data()] == damage) { return; }

  //     if (isNumber(storage[keyAttribute.data()])) {
  //       int storedDmg{ std::stoi(storage[keyAttribute.data()]) };
  //       attributeVal += storedDmg;
  //       attributeVal -= dmgVal;
  //       storage[keyAttribute.data()] = std::to_string(dmgVal);
  //       attribute = std::to_string(attributeVal);
  //       onEnterEvent(attribute, index);
  //     }


  //     if (!isNumber(storage[keyAttribute.data()])) {
  //       attributeVal -= dmgVal;
  //       storage[keyAttribute.data()] = std::to_string(dmgVal);
  //       attribute = std::to_string(attributeVal);
  //       onEnterEvent(attribute, index);
  //     }

  //   } catch (const std::exception& e) {
  //     outPutFile << e.what() << '\n';
  //     outPutFile << attribute << '\n';
  //     outPutFile << damage << '\n';
  //     outPutFile << keyAttribute << '\n';
  //   }
  // } };


  // auto onDamageEvent{ [&](std::string& damage, const Attributes& atr) -> void
  // {
  //   switch (atr) {
  //   case Attributes::str:
  //     applyDamage(damage, strAttribute, "strength", 0);
  //     break;
  //   case Attributes::dex:
  //     applyDamage(damage, dexAttribute, "dexterity", 1);
  //     break;
  //   case Attributes::con:
  //     applyDamage(damage, conAttribute, "constitution", 2);
  //     break;
  //   case Attributes::inti:
  //     applyDamage(damage, intAttribute, "intelligence", 3);
  //     break;
  //   case Attributes::wis:
  //     applyDamage(damage, wisAttribute, "wisdom", 4);
  //     break;
  //   case Attributes::cha:
  //     applyDamage(damage, chaAttribute, "charisma", 5);
  //     break;
  //   }
  // } };

  // inputStr.on_enter = [&] { onEnterEvent(strAttribute, 0); };
  // inputDex.on_enter = [&] { onEnterEvent(dexAttribute, 1); };
  // inputCon.on_enter = [&] { onEnterEvent(conAttribute, 2); };
  // inputInt.on_enter = [&] { onEnterEvent(intAttribute, 3); };
  // inputWis.on_enter = [&] { onEnterEvent(wisAttribute, 4); };
  // inputCha.on_enter = [&] { onEnterEvent(chaAttribute, 5); };

  // inputStrDamage.on_enter = [&] {
  //   onDamageEvent(strAttributeDamage, Attributes::str);
  // };
  // inputDexDamage.on_enter = [&] {
  //   onDamageEvent(dexAttributeDamage, Attributes::dex);
  // };
  // inputConDamage.on_enter = [&] {
  //   onDamageEvent(conAttributeDamage, Attributes::con);
  // };
  // inputIntDamage.on_enter = [&] {
  //   onDamageEvent(intAttributeDamage, Attributes::inti);
  // };
  // inputWisDamage.on_enter = [&] {
  //   onDamageEvent(wisAttributeDamage, Attributes::wis);
  // };
  // inputChaDamage.on_enter = [&] {
  //   onDamageEvent(chaAttributeDamage, Attributes::cha);
  // };


  // Component inputAddStr{ Input(&strAttribute, "Strength", inputStr) };
  // Component inputAddDex{ Input(&dexAttribute, "Dexterity", inputDex) };
  // Component inputAddWis{ Input(&wisAttribute, "Wisdom", inputWis) };
  // Component inputAddInt{ Input(&intAttribute, "Intelligences", inputInt) };
  // Component inputAddCon{ Input(&conAttribute, "Constitution", inputCon) };
  // Component inputAddCha{ Input(&chaAttribute, "Charisma", inputCha) };

  // // clang-format off
  // Component
  // inputDamageStr{Input(&strAttributeDamage,"Strength",inputStrDamage)};
  // Component
  // inputDamageDex{Input(&dexAttributeDamage,"Dexterity",inputDexDamage)};
  // Component
  // inputDamageWis{Input(&wisAttributeDamage,"Wisdom",inputWisDamage)};
  // Component
  // inputDamageInt{Input(&intAttributeDamage,"Intelligences",inputIntDamage)};
  // Component
  // inputDamageCon{Input(&conAttributeDamage,"Constitution",inputConDamage)};
  // Component
  // inputDamageCha{Input(&chaAttributeDamage,"Charisma",inputChaDamage)};
  // // clang-format on


  // auto attributeComponent{ Container::Horizontal({ Container::Vertical({
  //   Container::Horizontal({ inputAddStr, input }),
  //   Container::Horizontal({ inputAddDex, input }),
  //   Container::Horizontal({ inputAddCon, input }),
  //   Container::Horizontal({ inputAddInt, input }),
  //   Container::Horizontal({ inputAddWis, input }),
  //   Container::Horizontal({ inputAddCha, input }),
  //   Container::Horizontal({ inputDamageStr, input }),
  //   Container::Horizontal({ inputDamageDex, input }),
  //   Container::Horizontal({ inputDamageWis, input }),
  //   Container::Horizontal({ inputDamageInt, input }),
  //   Container::Horizontal({ inputDamageCon, input }),
  //   Container::Horizontal({ inputDamageCha, input }),
  // }) }) };


  // auto attributeRenderer{ Renderer(attributeComponent, [&] {
  //   auto inputWin{ window(text("Attributes"),
  //     hbox({ vbox({ hbox({
  //                     text("Str: "),
  //                     inputAddStr->Render(),
  //                   }) | size(WIDTH, EQUAL, 20)
  //                     | size(HEIGHT, EQUAL, 1),
  //              hbox({
  //                text("Dex: "),
  //                inputAddDex->Render(),
  //              }) | size(WIDTH, EQUAL, 20)
  //                | size(HEIGHT, EQUAL, 1),
  //              hbox({
  //                text("Con: "),
  //                inputAddCon->Render(),
  //              }) | size(WIDTH, EQUAL, 20)
  //                | size(HEIGHT, EQUAL, 1),
  //              hbox({
  //                text("Int: "),
  //                inputAddInt->Render(),
  //              }) | size(WIDTH, EQUAL, 20)
  //                | size(HEIGHT, EQUAL, 1),
  //              hbox({
  //                text("Wis: "),
  //                inputAddWis->Render(),
  //              }) | size(WIDTH, EQUAL, 20)
  //                | size(HEIGHT, EQUAL, 1),
  //              hbox({
  //                text("Cha: "),
  //                inputAddCha->Render(),
  //              }) | size(WIDTH, EQUAL, 20)
  //                | size(HEIGHT, EQUAL, 1),
  //              filler() }),
  //       separator(),
  //       // This is were I can implement drain or damage comopnents.
  //       vbox({ hbox({
  //                text("Str: "),
  //                inputDamageStr->Render(),
  //              }) | size(WIDTH, EQUAL, 20)
  //                | size(HEIGHT, EQUAL, 1),
  //         hbox({
  //           text("Dex: "),
  //           inputDamageDex->Render(),
  //         }) | size(WIDTH, EQUAL, 20)
  //           | size(HEIGHT, EQUAL, 1),
  //         hbox({
  //           text("Con: "),
  //           inputDamageCon->Render(),
  //         }) | size(WIDTH, EQUAL, 20)
  //           | size(HEIGHT, EQUAL, 1),
  //         hbox({
  //           text("Int: "),
  //           inputDamageInt->Render(),
  //         }) | size(WIDTH, EQUAL, 20)
  //           | size(HEIGHT, EQUAL, 1),
  //         hbox({
  //           text("Wis: "),
  //           inputDamageWis->Render(),
  //         }) | size(WIDTH, EQUAL, 20)
  //           | size(HEIGHT, EQUAL, 1),
  //         hbox({
  //           text("Cha: "),
  //           inputDamageCha->Render(),
  //         }) | size(WIDTH, EQUAL, 20)
  //           | size(HEIGHT, EQUAL, 1),
  //         filler() }),
  //       input->Render() | vscroll_indicator | frame | size(HEIGHT, EQUAL, 4)
  //         | flex })) };
  //   return vbox({
  //            hbox({ vbox({
  //                     inputWin | size(WIDTH, EQUAL, 60),
  //                   }),
  //              filler() })
  //              | size(HEIGHT, LESS_THAN, 8),
  //          })
  //          | flex_grow;
  // }) };

  // auto screen{ ScreenInteractive::TerminalOutput() };
  // screen.Loop(attributeRenderer);


  Attribute test{};
  test.render();


  return 0;
}
