#include <limits.h>
#include <fstream>
#include "../../../src/main/ir/schedule/Parallel.h"
#include "../../../src/main/writer/WriterBase.h"
#include "../../../src/main/writer/MerlinWriter.h"
#include "../../../src/main/ds/DesignSpaceBase.h"
#include "../../../src/main/ds/DesignSpaceCont.h"
#include "gtest/gtest.h"

using TheIR::WriterBase;
using TheIR::MerlinWriter;
using TheIR::DesignSpaceBase;
using TheIR::DesignSpaceCont;
using TheIR::Parallel;

// Test pragmas
TEST(MerlinWriterTest, Pragma) {
    std::ostringstream os;

    MerlinWriter writer(os);

    writer.writeParallelPragma();
    EXPECT_EQ("#pragma ACCEL parallel ", os.str());
    os.str("");
    os.clear();

    DesignSpaceCont<int> ds(1, 10, DesignSpaceBase::SEQ);
    writer.writeParallelPragma(ds);
    EXPECT_EQ("#pragma ACCEL parallel factor=auto_i_1_10\n", os.str());

}

