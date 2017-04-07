#include "Parallel.h"
#include "writer/WriterBase.h"
#include "util/Logger.h"
#include <iostream>
using namespace std;
using TheIR::Parallel;

void Parallel::compile(WriterBase &writer) {
    writer.writeLoopHead("i", 0, dup_ft.getMax(), 1);
    this->func();
    writer.writeln("}");

    return ;
}
