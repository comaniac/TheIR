#ifndef _SCHEDULE_H_
#define _SCHEDULE_H_
#include "ir/IR.h"

namespace TheIR {
    class Schedule : public IR {
        protected:
            std::string name;

        public:
            virtual void func() = 0;

            std::string getName() { return name; }
    };
}
#endif
