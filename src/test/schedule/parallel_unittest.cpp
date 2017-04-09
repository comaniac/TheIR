#include <limits.h>
#include "../../../src/main/ir/schedule/Parallel.h"
#include "gtest/gtest.h"

using TheIR::Parallel;

// Test parallel
TEST(ParallelTest, DupNum) {
    class PE : public Parallel {
        public:
            PE(int M): Parallel("PE", 2048, M) { ; }
            void func() { ; }
    };
    PE pe(7);

    EXPECT_EQ("PE", pe.getName());
    EXPECT_EQ(7, pe.getMaxDup());
    EXPECT_EQ(2048, pe.getTaskNum());

}

