#ifndef _PARALLEL_H_
#define _PARALLEL_H_

#include <iostream>
#include "writer/WriterBase.h"
#include "ds/DesignSpaceCont.h"
#include "Schedule.h"
using namespace std;

namespace TheIR {
    class Parallel : Schedule {
        protected:
            DesignSpaceCont<int> dup_ft;

        public:
            Parallel(int m, int M): dup_ft(m, M, DesignSpaceBase::SEQ) { }

            virtual void func() = 0;

            void compile(WriterBase &writer);
    };
}
#endif
