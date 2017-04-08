#ifndef _WRITER_BASE_H_
#define _WRITER_BASE_H_
#include <fstream>
#include "ir/IR.h"
#include "ir/schedule/Parallel.h"
#include "util/Logger.h"
using namespace std;

namespace TheIR {
    class WriterBase {
        public:
            WriterBase(string file_name) {
                try {
                    file.open(file_name, ios::out);
                }
                catch (const ifstream::failure& e) {
                    LOGGER.error("Cannot open " + file_name + " for writing");
                }
            }
            ~WriterBase() {
                file.close();
            }

            void write(string str) { file << str; }

            void writeln(string str) { file << str << endl; }

            virtual void write(Parallel &node) = 0;

        private:
            ofstream file;
    };
}

#endif
