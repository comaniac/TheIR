#ifndef _DESIGN_SPACE_CONT_H_
#define _DESIGN_SPACE_CONT_H_

#include <string>
#include <math.h>
#include "DesignSpaceBase.h"

namespace TheIR {
    template <class T>
    class DesignSpaceCont : DesignSpaceBase {
        public:
            DesignSpaceCont(T m, T M, enum INC_TYPE t) {
                min_val = m;
                if (t == POW2)
                    max_val = (int) pow(2.0, floor(log2(M)));
                else
                    max_val = M;
                inc_type = t;
            }

            T getMin() { return min_val; }
            T getMax() { return max_val; }
            std::string getIncrement() {
                switch (inc_type) {
                    case 0:
                        return "seq";
                    case 1:
                        return "power2";
                    default:
                        return "unknown";
                }
            }
        private:
            T min_val;
            T max_val;
            enum INC_TYPE inc_type;

    };
}
#endif
