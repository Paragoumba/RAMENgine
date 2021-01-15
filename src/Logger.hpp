#ifndef CONFINED_LOGGER_HPP
#define CONFINED_LOGGER_HPP

#include <fstream>
#include <memory>

namespace logger {

    enum Severity {
        INFO = 1,
        WARNING = 2,
        ERROR = 4
    };

    class Logger {
    public:
        static Logger& getLogger();

        void setFile(const char* path);

        void log(Severity severity, const char* message);
        void log(Severity severity, const std::string& message);
        void logi(const char* message);
        void logi(const std::string& message);
        void logw(const char* message);
        void logw(const std::string& message);
        void loge(const char* message);
        void loge(const std::string& message);

        Logger& operator<<(Severity s);
        Logger& operator<<(const char* message);
        Logger& operator<<(const std::string& message);

        ~Logger();

    private:
        static std::unique_ptr<Logger> logger;

        Severity mSeverity = Severity::ERROR;
        std::unique_ptr<std::ofstream> mFile;
    };
}

#endif //CONFINED_LOGGER_HPP
