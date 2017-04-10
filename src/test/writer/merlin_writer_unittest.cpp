#include <limits.h>
#include <fstream>
#include "../../../src/main/ds/DesignSpaceBase.h"
#include "../../../src/main/ds/DesignSpaceCont.h"
#include "../../../src/main/ir/schedule/Parallel.h"
#include "../../../src/main/writer/MerlinWriter.h"
#include "../../../src/main/writer/WriterBase.h"
#include "gtest/gtest.h"

using TheIR::WriterBase;
using TheIR::MerlinWriter;
using TheIR::DesignSpaceBase;
using TheIR::DesignSpaceCont;
using TheIR::Parallel;

void cleanStream(ostringstream &os) {
    os.str("");
    os.clear();
}

// Test pragmas
TEST(MerlinWriterTest, PragmaTest) {
    std::ostringstream os;

    MerlinWriter writer(os);

    writer.writeParallelPragma();
    EXPECT_EQ("#pragma ACCEL parallel ", os.str());
    cleanStream(os);

    DesignSpaceCont<int> ds(1, 10, DesignSpaceBase::SEQ);
    writer.writeParallelPragma(ds);
    EXPECT_EQ("#pragma ACCEL parallel factor=auto_i_1_10\n", os.str());
}

TEST(MerlinWriterTest, ParallelTest) {
    std::ostringstream os;
    MerlinWriter writer(os);

    class PE : public Parallel {
       public:
        PE(int M) : Parallel("PE", 2048, M) { ; }
        void func() { ; }
    };
    PE pe(7);
    writer.write(pe);

    std::string GOLDEN_RESULT =
        std::string("for (int PE_task = 0; PE_task < 2048; PE_task ++) ") +
        std::string("{\n#pragma ACCEL parallel factor=auto_i_1_7\n}\n");

    EXPECT_EQ(GOLDEN_RESULT, os.str());
}