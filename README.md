# ofxMenuBuilder

An add-on for [openFrameworks](https://github.com/openframeworks/openFrameworks) providing an interface for building macOS application menus.

To use this add-on with openFrameworks:
  - Download the repository;
  - Move the contents of the repository to `{OF_ROOT}/addons/ofxMenuBuilder/`;
  - Add ofxWindowOptions as an add-on to your project using the openFrameworks project generator.
  - Rename your project's `main.cpp` file to `main.mm` (or otherwise ensure that your IDE interprets it as an Objective-C++ file).

The `ofxMenuBuilder` class is only defined in Objective-C for macOS targets.

## Usage

Set `ofApp` to be a subclass of `MenuResponder`, which is defined in 'MenuResponder.h', and define the method `enact`, which will be called whenever a menu item is selected by the user.

```cpp
#include "MenuResponder.h"

class ofApp: public ofBaseApp, public MenuResponder
{
public:
  ofApp();
  
// ...

public:
  void enact(int32_t tag) noexcept override;
};
```
Create an instance of `ofxMenuBuilder` in `main`, prior to running your application, and use it to construct menus and menu items.

```cpp
#include "ofxMenuBuilder.h"

int main()
{
    ofSetupOpenGL(W, H, OF_WINDOW);
    
    ofApp *app = new ofApp();
    
    ofxMenuBuilder menu(app);
    
    // Remove all existing menu items.
    menu.removeAllMenuItems();
    
    // Begin a new menu, 'Export'.
    menu.beginNewMenu("Export");
    
    // Append an item to the 'Export' menu.
    // The item has tag 0x0, title 'Save Image', and keyboard shortcut `⌘ + i`.
    menu.appendMenuItem(0x0, "Save Image", "i", NSCommandKeyMask);
    
    // Begin a new menu, 'Options'.
    menu.beginNewMenu("Options");

    // Append an item to the 'Options' menu.
    // The item has tag 0x1, title 'Clear Screen', and keyboard shortcut `⇧ + ⌘ + x`.
    menu.appendMenuItem(0x1, "Clear Screen", "x", NSCommandKeyMask | NSShiftKeyMask);
    
    // Select the application's main menu.
    menu.selectMainMenu();
    
    // Prepend an item to the application's main menu.
    // The item has tag 0x2, title 'Save File', but no keyboard shortcut.
    menu.prependMenuItem(0x2, "Save File", "");
    
    ofRunApp(app);
}
```
Respond to the selection of menu items in `enact`. Each menu item is associated with a tag, which is passed to `enact` as a parameter.
```cpp
void ofApp::enact(int32_t tag) noexcept
{
  switch (tag)
  {
    case 0x0: // Save Image
    case 0x1: // Clear Screen
    case 0x2: // Save File

    default: return;
  }
}
```
