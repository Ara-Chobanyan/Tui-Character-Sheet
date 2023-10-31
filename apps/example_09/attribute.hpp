#pragma once

#include <ftxui/component/captured_mouse.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/util/ref.hpp>

#include <vector>
#include <string>
#include <unordered_map>
#include <exception>
#include <string_view>
#include <fstream>
#include <numeric>
#include <functional>


class Attribute
{
public:
  enum class Attributes { str, dex, con, inti, wis, cha };

  // clang-format off
  using modFuncType = std::function<std::string(const std::string&)>;
  using isNumberType = std::function<bool(const std::string&)>;
  using onEnterEventType = std::function<void(std::string&, int)>;
  using applyDamageType = std::function<void(std::string&, std::string&, std::string_view, int)>;
  using onDamageEventType = std::function<void(std::string&, const Attributes&)>;
  // clang-format on

  Attribute(std::string_view debugFile = "debug.txt");
  ~Attribute();

  void render();

protected:
  void setUpAttributeEvent();
  void setupInputAttribute();
  void setUpAttributeComponent();


private:
  ftxui::Element createAddComponent();
  ftxui::Element createDrainComponent();

  modFuncType m_modFunc{ [&](const std::string& attribute) -> std::string {
    int attributeInt{ (std::stoi(attribute) - 10) / 2 };
    return std::to_string(attributeInt);
  } };

  isNumberType m_isNumber{ [&](const std::string& s) -> bool {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) {
      return !std::isdigit(c);
    }) == s.end();
  } };

  onEnterEventType m_onEnterEvent{ [&](std::string& inputContent,
                                     int index) -> void {
    // std::string temp{ inputContent };
    inputEntries.at(index) = m_modFunc(inputContent);
    // Have no idea why I put this here, seems like it's useless
    // inputContent = temp;
  } };

  applyDamageType m_applyDamage{ [&](std::string& damage,
                                   std::string& attribute,
                                   std::string_view keyAttribute,
                                   int index) -> void {
    try {
      std::string storedDamageTaken{
        storageOfAtrDmgTaken[keyAttribute.data()]
      };
      if (storedDamageTaken == damage) { return; }

      int attributeVal{ std::stoi(attribute) };
      int dmgVal{ std::stoi(damage) };

      if (dmgVal < 0) { dmgVal = std::abs(dmgVal); }

      if (m_isNumber(storedDamageTaken)) {
        int storedDmg{ std::stoi(storageOfAtrDmgTaken[keyAttribute.data()]) };
        attributeVal += storedDmg;
        attributeVal -= dmgVal;
        storageOfAtrDmgTaken[keyAttribute.data()] = std::to_string(dmgVal);
        // Sense attribute is a reference it will affect the class field
        attribute = std::to_string(attributeVal);
        m_onEnterEvent(attribute, index);
      }

      if (!m_isNumber(storedDamageTaken)) {
        attributeVal -= dmgVal;
        storageOfAtrDmgTaken[keyAttribute.data()] = std::to_string(dmgVal);
        attribute = std::to_string(attributeVal);
        m_onEnterEvent(attribute, index);
      }

    } catch (const std::exception& e) {
      outPutFile << e.what() << '\n';
      outPutFile << attribute << '\n';
      outPutFile << damage << '\n';
      outPutFile << keyAttribute << '\n';
    }
  } };

  onDamageEventType m_onDamageEvent{ [&](std::string& damage,
                                       const Attributes& atr) -> void {
    switch (atr) {
    case Attributes::str:
      m_applyDamage(damage, strAttribute, "strength", 0);
      break;
    case Attributes::dex:
      m_applyDamage(damage, dexAttribute, "dexterity", 1);
      break;
    case Attributes::con:
      m_applyDamage(damage, conAttribute, "constitution", 2);
      break;
    case Attributes::inti:
      m_applyDamage(damage, intAttribute, "intelligence", 3);
      break;
    case Attributes::wis:
      m_applyDamage(damage, wisAttribute, "wisdom", 4);
      break;
    case Attributes::cha:
      m_applyDamage(damage, chaAttribute, "charisma", 5);
      break;
    }
  } };

  std::ofstream outPutFile;

  std::string strAttribute;
  std::string dexAttribute;
  std::string conAttribute;
  std::string intAttribute;
  std::string wisAttribute;
  std::string chaAttribute;

  std::string strAttributeDamage;
  std::string dexAttributeDamage;
  std::string conAttributeDamage;
  std::string intAttributeDamage;
  std::string wisAttributeDamage;
  std::string chaAttributeDamage;

  std::vector<std::string> inputEntries;
  int inputSelected{ 0 };
  ftxui::Component input{ ftxui::Menu(&inputEntries, &inputSelected) };

  ftxui::InputOption inputStr{ ftxui::InputOption() };
  ftxui::InputOption inputDex{ ftxui::InputOption() };
  ftxui::InputOption inputWis{ ftxui::InputOption() };
  ftxui::InputOption inputInt{ ftxui::InputOption() };
  ftxui::InputOption inputCha{ ftxui::InputOption() };
  ftxui::InputOption inputCon{ ftxui::InputOption() };

  ftxui::InputOption inputStrDmg{ ftxui::InputOption() };
  ftxui::InputOption inputDexDmg{ ftxui::InputOption() };
  ftxui::InputOption inputWisDmg{ ftxui::InputOption() };
  ftxui::InputOption inputIntDmg{ ftxui::InputOption() };
  ftxui::InputOption inputChaDmg{ ftxui::InputOption() };
  ftxui::InputOption inputConDmg{ ftxui::InputOption() };

  ftxui::Component inputAddStrComp;
  ftxui::Component inputAddDexComp;
  ftxui::Component inputAddwisComp;
  ftxui::Component inputAddIntComp;
  ftxui::Component inputAddConComp;
  ftxui::Component inputAddChaComp;

  ftxui::Component inputDmgStrComp;
  ftxui::Component inputDmgDexComp;
  ftxui::Component inputDmgwisComp;
  ftxui::Component inputDmgIntComp;
  ftxui::Component inputDmgConComp;
  ftxui::Component inputDmgChaComp;

  ftxui::Component attributeComponent;

  std::unordered_map<std::string, std::string> storageOfAtrDmgTaken{
    { "strength", strAttributeDamage },
    { "dexterity", dexAttributeDamage },
    { "constitution", conAttributeDamage },
    { "intelligence", intAttributeDamage },
    { "wisdom", wisAttributeDamage },
    { "cha", chaAttributeDamage },
  };
};
