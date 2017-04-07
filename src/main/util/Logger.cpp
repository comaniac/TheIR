#include "Logger.h"
#include <stdexcept>

using TheIR::Logger;
using namespace std;

int Logger::logLevel = 0;
const string Logger::kLogLevelDebug = "DEBUG";
const string Logger::kLogLevelInfo = "INFO";
const string Logger::kLogLevelWarning = "WARNING";
const string Logger::kLogLevelError = "ERROR";

Logger* Logger::pInstance = nullptr;

mutex Logger::sMutex;

Logger& Logger::instance()
{
	static Cleanup cleanup;

	lock_guard<mutex> guard(sMutex);
	if (pInstance == nullptr)
		pInstance = new Logger();
	return *pInstance;
}

Logger::Cleanup::~Cleanup()
{
	lock_guard<mutex> guard(Logger::sMutex);
	delete Logger::pInstance;
	Logger::pInstance = nullptr;
}

Logger::~Logger()
{

}

Logger::Logger()
{
    if ("debug" == currLogLevelStr)
        logLevel = 3;
    else if ("error" == currLogLevelStr)
        logLevel = 0;
    else if ("warning" == currLogLevelStr)
        logLevel = 1;
    else
        logLevel = 2;
}

void Logger::log(const string& inMessage, const string& inLogLevel, 
        const string funcName) {
	lock_guard<mutex> guard(sMutex);
	logHelper(inMessage, inLogLevel, funcName);
}

void Logger::log(const vector<string>& inMessages, const string& inLogLevel, 
        const string funcName) {
	lock_guard<mutex> guard(sMutex);
	for (size_t i = 0; i < inMessages.size(); i++) {
		logHelper(inMessages[i], inLogLevel, funcName);
	}
}

void Logger::logHelper(const std::string& inMessage, const std::string& inLogLevel, 
        const string funcName) {
    cerr << "[" << inLogLevel << "]";
    if (funcName != "")
     	cerr << "[" << funcName << "]";
    cerr << inMessage << endl;
}
