#include "ds/DesignSpaceCont.h"
#include "ds/DesignSpaceDist.h"
#include "writer/WriterBase.h"
#include "ir/schedule/Parallel.h"
using namespace TheIR;

void kernel(WriterBase &writer) {
    class PE : public Parallel {
        public:
            PE(int M): Parallel("PE", 2048, M) { ; }
            void func() { ; }
    };
    PE pe(7);
    writer.write(pe);
}
