#ifndef _MERLINWRITER_H_
#define _MERLINWRITER_H_
#include <fstream>
#include "WriterBase.h"
#include "util/Logger.h"
#include "ds/DesignSpaceCont.h"
using namespace std;

namespace TheIR {
    class MerlinWriter : public WriterBase {
        public:
            MerlinWriter(string file_name): WriterBase(file_name) { }

            using WriterBase::write;

            void write(Parallel &node);

            void writeParallelPragma();

            void writeParallelPragma(DesignSpaceCont<int> ds);
        private:
    };
}

#endif
