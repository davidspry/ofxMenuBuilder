#include "ofMain.h"
#include "Sketch.hpp"
#include "ofxMenuBuilder.h"

constexpr int W = 1100;
constexpr int H = 1100;

int main()
{
    ofSetupOpenGL(W, H, OF_WINDOW);

    Sketch* sketch = new Sketch();

    ofxMenuBuilder menu (sketch);

    menu.removeAllMenuItems();
    menu.beginNewMenu("Shapes");
    menu.appendMenuItem(0x0, "Circle",    "c", NSCommandKeyMask | NSShiftKeyMask);
    menu.appendMenuItem(0x1, "Square",    "v", NSCommandKeyMask | NSShiftKeyMask);
    menu.appendMenuItem(0x2, "Rectangle", "b", NSCommandKeyMask | NSShiftKeyMask);

    menu.selectMainMenu();
    menu.prependMenuItem(0x3, "Save Image", "s");

    menu.beginNewMenu("Options");
    menu.appendMenuItem(0x4, "Clear Screen", "m");

    ofRunApp(sketch);
}
