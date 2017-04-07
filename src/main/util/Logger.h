#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <mutex>

#define LOGGER (Logger::instance())
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define __LONGFUNC__ (string(__FILENAME__) + ":" + __func__)

namespace TheIR {

    // Definition of a multithread safe singleton logger class
    class Logger
    {
        public:
            static std::string currLogLevelStr;
            static int logLevel;
            static const std::string kLogLevelDebug;
            static const std::string kLogLevelInfo;
            static const std::string kLogLevelWarning;           
            static const std::string kLogLevelError;

            // Returns a reference to the singleton Logger object
            static Logger& instance();

            // Logs a single message at the given log level
            void log(const std::string& inMessage, 
                    const std::string& inLogLevel, 
                    std::string funcName = "");

            // Logs a vector of messages at the given log level
            void log(const std::vector<std::string>& inMessages, 
                    const std::string& inLogLevel,
                    std::string funcName = "");           

            // Log level: Error
            void error(const std::string& inMessage) {
                log(inMessage, kLogLevelError);
            }

            // Log level: Warning
            void warning(const std::string& inMessage) {
                if (logLevel >= 1)
                    log(inMessage, kLogLevelWarning);
            }
           
            // Log level: Info
            void info(const std::string& inMessage) {
                if (logLevel >= 2)
                    log(inMessage, kLogLevelInfo);
            }

            // Log level: Debug
            void debug(const std::string& funcName,
                    const std::string& inMessage) {
                if (logLevel >= 3)
                    log(inMessage, kLogLevelDebug, funcName);
            }

        protected:
            // Static variable for the one-and-only instance  
            static Logger* pInstance;

            // Embedded class to make sure the single Logger
            // instance gets deleted on program shutdown.
            friend class Cleanup;
            class Cleanup
            {
                public:
                    ~Cleanup();
            };

            // Logs message. The thread should own a lock on sMutex
            // before calling this function.
            void logHelper(const std::string& inMessage, 
                    const std::string& inLogLevel,
                    std::string funcName = "");

        private:
            Logger();
            virtual ~Logger();
            Logger(const Logger&);
            Logger& operator=(const Logger&);
            static std::mutex sMutex;
    };
}
#endif
