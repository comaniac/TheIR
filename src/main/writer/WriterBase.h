#ifndef _WRITER_BASE_H_
#define _WRITER_BASE_H_
#include <ostream>
#include "ir/IR.h"
#include "ir/schedule/Parallel.h"
#include "util/Logger.h"
using namespace std;

namespace TheIR {
class WriterBase {
   public:
    WriterBase(ostream &_os) : os(_os) {}

    void write(string str) { os << str; }

    void writeln(string str) { os << str << endl; }

    virtual void write(Parallel &node) = 0;

   private:
    ostream &os;
};
}

#endif
