//  ofxWindowOptions
//  Created by David Spry on 20/1/21.

#ifndef MENURESPONDER_H
#define MENURESPONDER_H

#include <cstdint>

/// @brief An object that can respond to menu actions.

class MenuResponder
{
public:
    /// @brief Enact a menu action.
    /// @param tag The tag number of the selected menu action.

    virtual void enact(int32_t tag) noexcept = 0;
};

#endif
