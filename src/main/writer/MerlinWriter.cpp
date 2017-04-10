#include "MerlinWriter.h"
#include "ds/DesignSpaceCont.h"
#include "ir/schedule/Parallel.h"
using namespace std;

using TheIR::MerlinWriter;

void MerlinWriter::write(Parallel &node) {
    string task_iter = node.getName() + "_task";

    write("for (int " + task_iter + " = 0; ");
    write(task_iter + " < " + to_string(node.getTaskNum()));
    writeln("; " + task_iter + " ++) {");
    writeParallelPragma(node.getDesignSpace());
    // write function
    writeln("}");

    return;
}

void MerlinWriter::writeParallelPragma(void) {
    write("#pragma ACCEL parallel ");
    return;
}

void MerlinWriter::writeParallelPragma(TheIR::DesignSpaceCont<int> ds) {
    writeParallelPragma();
    writeln("factor=auto_i_" + to_string(ds.getMin()) + "_" +
            to_string(ds.getMax()));
    return;
}
