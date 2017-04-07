#ifndef _DESIGN_SPACE_DIST_H_
#define _DESIGN_SPACE_DIST_H_

#include <vector>
#include <string>
#include <assert.h>
#include "DesignSpaceBase.h"
using namespace std; 

namespace TheIR {
    template <class T>
    class DesignSpaceDist : DesignSpaceBase {
        public:
            DesignSpaceDist(vector<T> vec) {
                vecVals = vec;
            }

            vector<T> getValSet() { return vecVals; }
            int getSize() { return vecVals.size(); }
            T getVal(int idx) { 
                assert(idx < getSize());
                return vecVals[idx];
            }

        private:
            vector<T> vecVals;
    };
}
#endif
