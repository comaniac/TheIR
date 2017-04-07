#ifndef _WRITER_BASE_H_
#define _WRITER_BASE_H_
#include <fstream>
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

            void write(string str) {
                file << str;
            }

            void writeln(string str) {
                file << str << endl;
            }

            void writeLoopHead(string var, int init, 
                    int cond, int step);

        private:
            ofstream file;
    };
}

#endif
