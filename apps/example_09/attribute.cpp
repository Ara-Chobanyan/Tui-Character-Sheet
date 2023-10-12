#include "attribute.hpp"

//-------------------------------------------------------------------------------------------------
Attribute::Attribute(std::string_view debugFile)
  : outPutFile{ debugFile.data() }, inputEntries(6, "")
{}

//-------------------------------------------------------------------------------------------------
Attribute::~Attribute() { outPutFile.close(); };

//-------------------------------------------------------------------------------------------------
void Attribute::setUpAttributeEvent()
{
  inputStr.on_enter = [this] { m_onEnterEvent(strAttribute, 0); };
  inputDex.on_enter = [this] { m_onEnterEvent(dexAttribute, 1); };
  inputCon.on_enter = [this] { m_onEnterEvent(conAttribute, 2); };
  inputInt.on_enter = [this] { m_onEnterEvent(intAttribute, 3); };
  inputWis.on_enter = [this] { m_onEnterEvent(wisAttribute, 4); };
  inputCha.on_enter = [this] { m_onEnterEvent(chaAttribute, 5); };


  inputStrDmg.on_enter = [this] {
    m_onDamageEvent(strAttributeDamage, Attributes::str);
  };
  inputDexDmg.on_enter = [this] {
    m_onDamageEvent(dexAttributeDamage, Attributes::dex);
  };
  inputConDmg.on_enter = [this] {
    m_onDamageEvent(conAttributeDamage, Attributes::con);
  };
  inputIntDmg.on_enter = [this] {
    m_onDamageEvent(intAttributeDamage, Attributes::inti);
  };
  inputWisDmg.on_enter = [this] {
    m_onDamageEvent(wisAttributeDamage, Attributes::wis);
  };
  inputChaDmg.on_enter = [this] {
    m_onDamageEvent(chaAttributeDamage, Attributes::cha);
  };
}

//-------------------------------------------------------------------------------------------------
void Attribute::setupInputAttribute()
{
  inputAddStrComp = { Input(&strAttribute, "Strength", inputStr) };
  inputAddDexComp = { Input(&dexAttribute, "Dexterity", inputDex) };
  inputAddwisComp = { Input(&wisAttribute, "Wisdom", inputWis) };
  inputAddIntComp = { Input(&intAttribute, "Intelligences", inputInt) };
  inputAddConComp = { Input(&conAttribute, "Constitution", inputCon) };
  inputAddChaComp = { Input(&chaAttribute, "Charisma", inputCha) };


  // clang-format off
  inputDmgStrComp = {Input(&strAttributeDamage,"Strength",inputStrDmg)};
  inputDmgDexComp = {Input(&dexAttributeDamage,"Dexterity",inputDexDmg)};
  inputDmgwisComp = {Input(&wisAttributeDamage,"Wisdom",inputWisDmg)};
  inputDmgIntComp = {Input(&intAttributeDamage,"Intelligences",inputIntDmg)};
  inputDmgConComp = {Input(&conAttributeDamage,"Constitution",inputConDmg)};
  inputDmgChaComp = {Input(&chaAttributeDamage,"Charisma",inputChaDmg)};
  // clang-format on
};

//-------------------------------------------------------------------------------------------------
void Attribute::setUpAttributeComponent()
{
  attributeComponent = {
    ftxui::Container::Horizontal({ ftxui::Container::Vertical({
      ftxui::Container::Horizontal({ inputAddStrComp, input }),
      ftxui::Container::Horizontal({ inputAddDexComp, input }),
      ftxui::Container::Horizontal({ inputAddConComp, input }),
      ftxui::Container::Horizontal({ inputAddIntComp, input }),
      ftxui::Container::Horizontal({ inputAddwisComp, input }),
      ftxui::Container::Horizontal({ inputAddChaComp, input }),
      ftxui::Container::Horizontal({ inputDmgStrComp, input }),
      ftxui::Container::Horizontal({ inputDmgDexComp, input }),
      ftxui::Container::Horizontal({ inputDmgwisComp, input }),
      ftxui::Container::Horizontal({ inputDmgIntComp, input }),
      ftxui::Container::Horizontal({ inputDmgConComp, input }),
      ftxui::Container::Horizontal({ inputDmgChaComp, input }),
    }) })
  };
};

//-------------------------------------------------------------------------------------------------
void Attribute::render()
{
  setUpAttributeEvent();
  setupInputAttribute();
  setUpAttributeComponent();

  auto attributeRender{ Renderer(attributeComponent, [&] {
    auto inputWin{ window(ftxui::text("Attributes"),
      ftxui::hbox({ createAddComponent(),
        ftxui::separator(),
        createDrainComponent(),
        input->Render() | ftxui::vscroll_indicator | ftxui::frame
          | size(ftxui::HEIGHT, ftxui::EQUAL, 4) | ftxui::flex })) };

    return ftxui::vbox({
             ftxui::hbox({ ftxui::vbox({
                             inputWin | size(ftxui::WIDTH, ftxui::EQUAL, 60),
                           }),
               ftxui::filler() })
               | size(ftxui::HEIGHT, ftxui::LESS_THAN, 8),
           })
           | ftxui::flex_grow;
  }) };

  auto screen{ ftxui::ScreenInteractive::TerminalOutput() };
  screen.Loop(attributeRender);
};

//-------------------------------------------------------------------------------------------------
ftxui::Element Attribute::createAddComponent()
{
  return ftxui::vbox({ ftxui::hbox({
                         ftxui::text("Str: "),
                         inputAddStrComp->Render(),
                       }) | size(ftxui::WIDTH, ftxui::EQUAL, 20)
                         | size(ftxui::HEIGHT, ftxui::EQUAL, 1),
    ftxui::hbox({
      ftxui::text("Dex: "),
      inputAddDexComp->Render(),
    }) | size(ftxui::WIDTH, ftxui::EQUAL, 20)
      | size(ftxui::HEIGHT, ftxui::EQUAL, 1),
    ftxui::hbox({
      ftxui::text("Con: "),
      inputAddConComp->Render(),
    }) | size(ftxui::WIDTH, ftxui::EQUAL, 20)
      | size(ftxui::HEIGHT, ftxui::EQUAL, 1),
    ftxui::hbox({
      ftxui::text("Int: "),
      inputAddIntComp->Render(),
    }) | size(ftxui::WIDTH, ftxui::EQUAL, 20)
      | size(ftxui::HEIGHT, ftxui::EQUAL, 1),
    ftxui::hbox({
      ftxui::text("Wis: "),
      inputAddwisComp->Render(),
    }) | size(ftxui::WIDTH, ftxui::EQUAL, 20)
      | size(ftxui::HEIGHT, ftxui::EQUAL, 1),
    ftxui::hbox({
      ftxui::text("Cha: "),
      inputAddChaComp->Render(),
    }) | size(ftxui::WIDTH, ftxui::EQUAL, 20)
      | size(ftxui::HEIGHT, ftxui::EQUAL, 1),
    ftxui::filler() });
}

//-------------------------------------------------------------------------------------------------
ftxui::Element Attribute::createDrainComponent()
{
  return ftxui::vbox({ ftxui::hbox({
                         ftxui::text("Str: "),
                         inputDmgStrComp->Render(),
                       }) | size(ftxui::WIDTH, ftxui::EQUAL, 20)
                         | size(ftxui::HEIGHT, ftxui::EQUAL, 1),
    ftxui::hbox({
      ftxui::text("Dex: "),
      inputDmgDexComp->Render(),
    }) | size(ftxui::WIDTH, ftxui::EQUAL, 20)
      | size(ftxui::HEIGHT, ftxui::EQUAL, 1),
    ftxui::hbox({
      ftxui::text("Con: "),
      inputDmgConComp->Render(),
    }) | size(ftxui::WIDTH, ftxui::EQUAL, 20)
      | size(ftxui::HEIGHT, ftxui::EQUAL, 1),
    ftxui::hbox({
      ftxui::text("Int: "),
      inputDmgIntComp->Render(),
    }) | size(ftxui::WIDTH, ftxui::EQUAL, 20)
      | size(ftxui::HEIGHT, ftxui::EQUAL, 1),
    ftxui::hbox({
      ftxui::text("Wis: "),
      inputDmgwisComp->Render(),
    }) | size(ftxui::WIDTH, ftxui::EQUAL, 20)
      | size(ftxui::HEIGHT, ftxui::EQUAL, 1),
    ftxui::hbox({
      ftxui::text("Cha: "),
      inputDmgChaComp->Render(),
    }) | size(ftxui::WIDTH, ftxui::EQUAL, 20)
      | size(ftxui::HEIGHT, ftxui::EQUAL, 1),
    ftxui::filler() });
};
