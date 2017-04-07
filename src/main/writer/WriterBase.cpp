#include "WriterBase.h"
using namespace std;

using TheIR::WriterBase;

void WriterBase::writeLoopHead(string var, int init, 
        int cond, int step) {
    write("for (int " + var + " = " + to_string(init));
    write("; " + var + " < " + to_string(cond));
    write("; " + var + " += " + to_string(step));
    writeln(") {");

    return ;
}
