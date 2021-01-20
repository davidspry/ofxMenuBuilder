#include "Sketch.hpp"

void Sketch::setup()
{
    ofBackground(5);
    
    path.setFilled(false);
    path.setStrokeWidth(2.0f);
    path.setCircleResolution(128);
    path.setStrokeColor(ofColor::whiteSmoke);
}

void Sketch::update()
{
    
}

void Sketch::draw()
{
    const int x = 0.5f * ofGetWidth();
    const int y = 0.5f * ofGetHeight();
    
    path.draw(x, y);
}

void Sketch::enact(int32_t tag) noexcept
{
    constexpr static float size = 250.0f;
    
    switch (tag)
    {
        case 0x0:
        {
            path.clear();
            path.circle(0.0f, 0.0f, size * 0.5f);
            return;
        }
            
        case 0x1:
        {
            
            path.clear();
            path.rectangle(-size * 0.5f, -size * 0.5f, size, size);
            return;
        }

        case 0x2:
        {
            path.clear();
            path.rectangle(-size, -size * 0.5f, -size * 0.5f, size * 2.0f, size);
            return;
        }
        
        case 0x3:
        {
            ofSaveScreen("Image.png");
            return;
        }

        case 0x4:
        {
            path.clear();
            return;
        }

        default: break;
    }
}
