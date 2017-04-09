#include <limits.h>
#include "../../../src/main/ds/DesignSpaceBase.h"
#include "../../../src/main/ds/DesignSpaceCont.h"
#include "../../../src/main/ds/DesignSpaceDist.h"
#include "gtest/gtest.h"

using TheIR::DesignSpaceCont;
using TheIR::DesignSpaceDist;
using TheIR::DesignSpaceBase;

// Test continuous design space
TEST(DesignSpaceTest, Continuous) {
    DesignSpaceCont<int> ds_seq(1, 10, DesignSpaceBase::SEQ);

    EXPECT_EQ(1, ds_seq.getMin());
    EXPECT_EQ(10, ds_seq.getMax());
    EXPECT_EQ("seq", ds_seq.getIncrement());

    DesignSpaceCont<int> ds_pow2(1, 50, DesignSpaceBase::POW2);

    EXPECT_EQ(1, ds_pow2.getMin());
    EXPECT_EQ(32, ds_pow2.getMax());
    EXPECT_EQ("power2", ds_pow2.getIncrement());

}

// Test discrete design space
TEST(DesignSpaceTest, Discrete) {
    vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);
    DesignSpaceDist<int> ds(vec);

    EXPECT_EQ(10, ds.getSize());
    EXPECT_EQ(0, ds.getVal(0));
}