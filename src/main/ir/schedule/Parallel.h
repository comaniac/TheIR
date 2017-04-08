#ifndef _PARALLEL_H_
#define _PARALLEL_H_

#include <iostream>
#include "ds/DesignSpaceCont.h"
#include "Schedule.h"
using namespace std;

namespace TheIR {
    class Parallel : public Schedule {
        protected:
            DesignSpaceCont<int> dup_ft;
            int task_num;

        public:
            Parallel(string n, int task, int max_dup): 
                dup_ft(1, max_dup, DesignSpaceBase::SEQ) { 
                this->name = n;
                this->task_num = task;
            }

            virtual void func() = 0;

            int getMaxDup() { return dup_ft.getMax(); }

            int getTaskNum() { return task_num; }

            DesignSpaceCont<int> getDesignSpace() { return dup_ft; }
    };
}
#endif
