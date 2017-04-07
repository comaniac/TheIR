#ifndef _MERLINWRITER_H_
#define _MERLINWRITER_H_
#include <fstream>
#include "WriterBase.h"
#include "util/Logger.h"
using namespace std;

namespace TheIR {
    class MerlinWriter : public WriterBase {
        public:
            MerlinWriter(string file_name): WriterBase(file_name) { }

            void writeParallelPragma() {
                ;
            }
        private:
    };
}

#endif
