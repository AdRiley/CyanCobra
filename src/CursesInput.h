#ifndef CURSESINPUT_H
#define CURSESINPUT_H

#include "Input.h"

class CursesInput : public Input
{
public:
    virtual ~CursesInput() {}
    virtual Command GetCommand();
};

#endif
