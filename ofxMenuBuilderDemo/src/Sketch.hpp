#pragma once

#include "ofMain.h"
#include "MenuResponder.h"

class Sketch: public ofBaseApp, public MenuResponder
{
public:
    Sketch() {}
    
public:
    void setup()  override;
    void update() override;
    void draw()   override;

public:
    void enact(int32_t tag) noexcept override;
    
private:
    ofPath path;
};
