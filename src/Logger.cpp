#include <iostream>

#include "Logger.hpp"

// May 03 19:39:18 - \0
// \------------------/
//       19 chars
#define TIME_LENGTH 19

using logger::Logger;
using logger::Severity;
using Severity::INFO;
using Severity::WARNING;
using Severity::ERROR;

std::unique_ptr<Logger> Logger::logger;

void Logger::setFile(const char* path){

    if (mFile != nullptr){

        mFile->close();

    }

    mFile = std::make_unique<std::ofstream>(path, std::ofstream::app);

}

void Logger::log(Severity severity, const char* message){

    std::string s;

    {

        // May 20 17:20:01 - [INFO] Test
        char timeStr[TIME_LENGTH];
        time_t rawTime;

        time(&rawTime);
        strftime(timeStr, TIME_LENGTH, "%b %d %T - ", localtime(&rawTime));
        s += timeStr;

    }

    s += '[';
    s += (severity == INFO ? "INFO" : severity == WARNING ? "WARN" : severity == ERROR ? "ERRO" : "UNKN");
    s += "] ";
    s += message;
    s += '\n';

    switch (severity){
        case INFO:
        case WARNING:
            std::cout << s;
            std::cout.flush();
            break;

        case ERROR:
        default:
            std::cerr << s;
            std::cerr.flush();
            break;
    }

    if (mFile != nullptr){

        *mFile << s;
        mFile->flush();

    }
}

void Logger::log(Severity severity, const std::string& message){

    log(severity, message.c_str());

}

void Logger::logi(const char* message){

    log(INFO, message);

}

void Logger::logi(const std::string& message){

    logi(message.c_str());

}

void Logger::logw(const char* message){

    log(WARNING, message);

}

void Logger::logw(const std::string& message){

    logw(message.c_str());

}

void Logger::loge(const char* message){

    log(ERROR, message);

}

void Logger::loge(const std::string& message){

    loge(message.c_str());

}

Logger& Logger::getLogger(){

    if (logger == nullptr){

        logger = std::make_unique<Logger>();

    }

    return *logger;

}

Logger& Logger::operator<<(Severity s){

    mSeverity = s;

    return *this;

}

Logger& Logger::operator<<(const char* message){

    log(mSeverity, message);

    return *this;

}

Logger& Logger::operator<<(const std::string& message){

    log(mSeverity, message);

    return *this;

}

Logger::~Logger(){

    if (mFile != nullptr){

        mFile->close();

    }
}
