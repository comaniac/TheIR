#ifndef _MERLINWRITER_H_
#define _MERLINWRITER_H_
#include <fstream>
#include "WriterBase.h"
#include "ds/DesignSpaceCont.h"
#include "util/Logger.h"
using namespace std;

namespace TheIR {
class MerlinWriter : public WriterBase {
   public:
    MerlinWriter(ostream &os) : WriterBase(os) {}

    using WriterBase::write;

    void write(Parallel &node);

    void writeParallelPragma(void);

    void writeParallelPragma(DesignSpaceCont<int> ds);

   private:
};
}

#endif
