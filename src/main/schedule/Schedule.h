#ifndef _SCHEDULE_H_
#define _SCHEDULE_H_
#include "writer/WriterBase.h"

namespace TheIR {
    class Schedule {
        public:
            virtual void func() = 0;

            virtual void compile(WriterBase &writer) = 0;
    };
}
#endif
