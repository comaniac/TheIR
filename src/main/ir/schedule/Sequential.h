#ifndef _SEQUENTIAL_H_
#define _SEQUENTIAL_H_

#include <iostream>
#include "Schedule.h"
#include "ds/DesignSpaceCont.h"
using namespace std;

namespace TheIR {
class Sequential : public Schedule {
   public:
    Sequential(string n) : this->name = n {}

    virtual void func() = 0;
};
}
#endif
