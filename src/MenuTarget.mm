//  ofxWindowOptions
//  Created by David Spry on 20/1/21.

#include "MenuTarget.h"

@implementation MenuTarget

-(id)init:(MenuResponder*)target
{
    self = [super init];
    
    if (self) {
        _target = target;
    }
    
    return self;
}

-(void)enact:(id)caller
{
    _target->enact(static_cast<int32_t>(((NSMenuItem*) caller).tag));
}

@end
