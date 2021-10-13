#ifndef FTXUI_COMPONENT_EVENT_HPP
#define FTXUI_COMPONENT_EVENT_HPP

#include <ftxui/component/mouse.hpp>  // for Mouse
#include <string>                     // for string, operator==
#include <vector>

namespace ftxui {

class ScreenInteractive;
class ComponentBase;

/// @brief Represent an event. It can be key press event, a terminal resize, or
/// more ...
///
/// For example:
/// - Printable character can be created using Event::Character('a').
/// - Some special are predefined, like Event::ArrowLeft.
/// - One can find arbitrary code for special Events using:
///   ./example/util/print_key_press
///  For instance, CTLR+A maps to Event::Special({1});
///
/// Useful documentation about xterm specification:
/// https://invisible-island.net/xterm/ctlseqs/ctlseqs.html
struct Event {
  // --- Constructor section ---------------------------------------------------
  [[nodiscard]] static Event Character(std::string);
  [[nodiscard]] static Event Character(char);
  [[nodiscard]] static Event Character(wchar_t);
  [[nodiscard]] static Event Special(std::string);
  [[nodiscard]] static Event Mouse(std::string, Mouse mouse);
  [[nodiscard]] static Event CursorReporting(std::string, int x, int y);

  // --- Arrow ---
  static const Event ArrowLeft;
  static const Event ArrowRight;
  static const Event ArrowUp;
  static const Event ArrowDown;

  // --- Other ---
  static const Event Backspace;
  static const Event Delete;
  static const Event Return;
  static const Event Escape;
  static const Event Tab;
  static const Event TabReverse;
  static const Event F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12;

  static const Event Home;
  static const Event End;

  static const Event PageUp;
  static const Event PageDown;

  // --- Custom ---
  static Event Custom;

  //--- Method section ---------------------------------------------------------
  [[nodiscard]] bool is_character() const noexcept { return type_ ==
                                                      Type::Character; }
  [[nodiscard]] std::string character() const { return input_; }

  [[nodiscard]] bool is_mouse() const noexcept { return type_ == Type::Mouse; }
  [[nodiscard]] struct Mouse& mouse() noexcept {
    return mouse_;
  }

  [[nodiscard]] bool is_cursor_reporting() const noexcept { return type_ == Type::CursorReporting; }
  [[nodiscard]] int cursor_x() const noexcept { return cursor_.x; }
  [[nodiscard]] int cursor_y() const noexcept { return cursor_.y; }

  [[nodiscard]] const std::string& input() const noexcept { return input_; }

  bool operator==(const Event& other) const noexcept { return input_ == other.input_; }
  bool operator!=(const Event& other) const noexcept { return !operator==(other); }

  //--- State section ----------------------------------------------------------
  ScreenInteractive* screen_ = nullptr;
 private:
  friend ComponentBase;
  friend ScreenInteractive;
  enum class Type {
    Unknown,
    Character,
    Mouse,
    CursorReporting,
  };
  Type type_ = Type::Unknown;

  struct Cursor {
    int x;
    int y;
  };

  union {
    struct Mouse mouse_;
    struct Cursor cursor_;
  };
  std::string input_;
};

}  // namespace ftxui

#endif /* end of include guard: FTXUI_COMPONENT_EVENT_HPP */

// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
