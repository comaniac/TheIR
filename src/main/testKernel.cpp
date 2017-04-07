#include "ds/DesignSpaceCont.h"
#include "ds/DesignSpaceDist.h"
#include "writer/WriterBase.h"
#include "schedule/Parallel.h"
using namespace TheIR;

void kernel(WriterBase &writer) {
    class PE : public Parallel {
        public:
            PE(int m, int M): Parallel(m, M) { ; }
            void func() { ; }
    };
    PE pe(1, 7);
    pe.compile(writer);
}
