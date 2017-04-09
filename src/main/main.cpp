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
    ofstream file;

    try{
        file.open(GEN_FILE_NAME, ios::out);
    }
    catch (const ifstream::failure& e) {
        LOGGER.error("Cannot open" + string(GEN_FILE_NAME) + " for writing");
    }

    MerlinWriter writer(file);
    Logger::currLogLevelStr = "info";
    kernel(writer);
    return 0;
}
