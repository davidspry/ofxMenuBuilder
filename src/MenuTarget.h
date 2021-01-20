//  ofxWindowOptions
//  Created by David Spry on 20/1/21.

#ifdef  __OBJC__
#ifndef MENUTARGET_H
#define MENUTARGET_H

#include <Cocoa/Cocoa.h>
#include "MenuResponder.h"

/// @brief A target of menu actions whose purpose is to relay messages to the C++ context.

@interface MenuTarget: NSObject

@property (nonatomic, assign) MenuResponder* target;

-(id)init:(MenuResponder*)application;
-(void)enact:(id)caller;

@end

#endif
#endif
