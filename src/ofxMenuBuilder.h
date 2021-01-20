//  ofxWindowOptions
//  Created by David Spry on 20/1/21.

#ifdef  __OBJC__
#ifdef  TARGET_OSX
#ifndef OFXMENUBUILDER_H
#define OFXMENUBUILDER_H

#include "ofMain.h"
#include <Cocoa/Cocoa.h>
#include "MenuResponder.h"
#include "MenuTarget.h"

/// @brief A class for building a macOS application's menu bar, intended to be used with openFrameworks.

class ofxMenuBuilder
{
public:
    ofxMenuBuilder(MenuResponder* responder):
    selectedMenu(nullptr)
    {
        target = [[MenuTarget alloc] init: responder];
    }
    
public:
    /// @brief Remove all items from the application's menu bar.

    inline void removeAllMenuItems()
    {
        [getMainMenuBar() removeAllItems];
        
        initialiseMainMenu();
    }
    
    /// @brief Select the application's main menu.

    inline void selectMainMenu()
    {
        if ([[getMainMenuBar() itemAtIndex:0] hasSubmenu])
        {
            selectedMenu = [[getMainMenuBar() itemAtIndex:0] submenu];
        }
    }

    /// @brief Begin a new menu with the given title.
    /// @param menuTitle The desired title of the new menu.

    inline void beginNewMenu(const char * menuTitle)
    {
        NSMenu * mainMenu = getMainMenuBar();
        NSString *  title = [NSString stringWithUTF8String:menuTitle];
        NSMenuItem * item = [NSMenuItem alloc];
        NSMenu * selected = [[NSMenu alloc] initWithTitle:title];
        [item setSubmenu:selected];
        [mainMenu addItem:item];

        selectedMenu = selected;
    }

    /// @brief Append a new menu item to the currently selected menu.
    /// @param tag The action tag for the menu item's action.
    /// @param name The desired name for the menu item.
    /// @param key The key that should be associated with this command.
    /// @param modifierFlags The modifier keys that should be associated with this command.
    /// @note  Either select the main menu or begin a new menu before calling this method.
    /// @note  Passing an empty string literal as the key will preclude the association of the menu item with a key.
    /// @return A flag to indicate whether the menu item was added successfully or not.

    inline bool appendMenuItem(int32_t tag, const char * name, const char * key, NSEventModifierFlags modifierFlags = NSCommandKeyMask)
    {
        if (selectedMenu == nullptr)
            return false;
        
        NSMenuItem *  item = [NSMenuItem alloc];
        NSString *   title = [NSString stringWithUTF8String:name];
        NSString * command = [NSString stringWithUTF8String:key];

        [item setTag:tag];
        [item setTarget:target];
        [item setTitle:title];
        [item setAction:@selector(enact:)];
        [item setKeyEquivalent:command];
        [item setKeyEquivalentModifierMask:modifierFlags];
        [selectedMenu addItem:item];
        
        return true;
    }
    
    /// @brief Prepend a new menu item to the currently selected menu.
    /// @param tag The action tag for the menu item's action.
    /// @param name The desired name for the menu item.
    /// @param key The key that should be associated with this command.
    /// @param modifierFlags The modifier keys that should be associated with this command.
    /// @note  Either select the main menu or begin a new menu before calling this method.
    /// @note  Passing an empty string literal as the key will preclude the association of the menu item with a key.
    /// @return A flag to indicate whether the menu item was added successfully or not.
    
    inline bool prependMenuItem(int32_t tag, const char * name, const char * key, NSEventModifierFlags modifierFlags = NSCommandKeyMask)
    {
        if (selectedMenu == nullptr)
            return false;
        
        NSMenuItem *  item = [NSMenuItem alloc];
        NSString *   title = [NSString stringWithUTF8String:name];
        NSString * command = [NSString stringWithUTF8String:key];

        [item setTag:tag];
        [item setTarget:target];
        [item setTitle:title];
        [item setAction:@selector(enact:)];
        [item setKeyEquivalent:command];
        [item setKeyEquivalentModifierMask:modifierFlags];
        [selectedMenu insertItem:item atIndex:0];

        return true;
    }
    
private:
    inline NSMenu * const getMainMenuBar() const
    {
        return [[NSApplication sharedApplication] mainMenu];
    }
    
    /// @brief Initialise the main menu after the menu bar has been cleared of all menu items.
    /// @note  The menu bar must have been cleared of all items before calling this method.

    inline void initialiseMainMenu()
    {
        beginNewMenu("");

        NSMenuItem * quit = [NSMenuItem alloc];
        
        [quit setTitle:@"Quit"];
        [quit setAction:@selector(terminate:)];
        [quit setKeyEquivalent:@"q"];
        [quit setKeyEquivalentModifierMask:NSCommandKeyMask];
        [selectedMenu addItem:quit];
    }

private:
    id target;
    
private:
    NSMenu * selectedMenu;
};

#endif
#endif
#endif
