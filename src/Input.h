#ifndef INPUT_H
#define INPUT_H

#include "Command.h"

class Input
{
public:
    virtual ~Input() {}
    virtual Command GetCommand() = 0;
};

#endif
