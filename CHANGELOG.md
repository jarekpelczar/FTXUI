Changelog
=========

Unreleased (development) 
------------------------

## Bug
- On Unix system, fallback to {80,25} screen dimension on failure.

## CMake
Added:
- Support for shared library, via `BUILD_SHARED_LIBS` option.
- Add library version and symlinks.

0.10 (2021-09-30)
--------------------

## Bug
- Fix the automated merge of borders.

### Dom
 - `vscroll_indicator`. Show a scrollbar indicator on the right.

### Component
 - `Maybe`: Display an component conditionnally based on a boolean.
 - `Dropdown`: A dropdown select list.

0.9 (2021-09-26)
----------------

The initial release where changelog where written.

This version includes:

### screen
- Style:
  - Bold.
  - Blink.
  - Dim.
  - Inverted.
  - Underlined.
  - Foreground color.
  - Background color.
- Support for UTF8 unicode.
  - Full wide character: 测试.
  - Combining characters: a⃒
- A Stencil buffer.
- Automatically merge box drawing characters.
- Detect terminal dimension.

### DOM

- Element:
  - `text` & `vtext`
  - `separator` and 5 variations.
  - `gauge`
  - `border` and 6 variations.
  - `window`
  - `spinner`
  - `paragraph` and `hflow`.

- Layout:
  - `hbox`
  - `vbox`
  - `dbox`
  - `gridbox`
  - `frame`: Drawing inside a virtual area, potentially larger than the real
             one.
  - `focus`, `select`: scroll the inner view of a frame, to be in view.
  - `flex` & 8 variations. `filler`
  
- Decorators:
  - `bold`
  - `dim`
  - `inverted`
  - `blink`
  - `color`
  - `bgcolor`
  - `clearunder`

### Component

- Container:
  - `Container::Vertical`
  - `Container::Horizontal`
  - `Container::Tab`
- `Button`
- `Checkbox`
- `Input`
- `Menu`
- `MenuEntry`
- `Radiobox`
- `Toggle`
- `Slider`
- `Renderer` & variations
- `CatchEvent`

### MISC

- Fuzzer
- Tests using gtest.
- Doxygen documentation
- IWYU
- 52 examples.
- Support for WebAssembly.
- Support for Window and fallback for broken terminal.
