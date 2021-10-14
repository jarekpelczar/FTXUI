#include <ftxui/dom/elements.hpp>  // for text, operator|, underlined, Fit, hbox, Element
#include <ftxui/screen/screen.hpp>  // for Full, Screen
#include <memory>                   // for allocator

#include "ftxui/dom/node.hpp"    // for Render
#include "ftxui/screen/box.hpp"  // for ftxui

int main() {
  using namespace ftxui;
  auto document =  //
      hbox({
          text("This text is "),
          text("underlined") | underlined,
          text(". Do you like it?"),
      });
  auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
  Render(screen, document);
  screen.Print();

  return 0;
}

// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
