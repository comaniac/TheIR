#include <iostream>
#include <vector>
#include "util/Logger.h"
#include "writer/MerlinWriter.h"
using namespace TheIR;

// Output file
#define GEN_FILE_NAME "gen.cpp"

// Default log level
string Logger::currLogLevelStr = "info";

// User input source code
extern void kernel(WriterBase &writer);

int main(void) {
    MerlinWriter writer(GEN_FILE_NAME);
    Logger::currLogLevelStr = "info";
    kernel(writer);
    return 0;
}
