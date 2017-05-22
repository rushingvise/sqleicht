#pragma once

#include <string>
#include <sstream>

namespace sqleicht {
    namespace StringUtils {
        template<typename ... Args>
        std::string concatenate(Args const &... args) {
            std::ostringstream stream;
            using List= int[];
            (void) List{0, ((void) (stream << args), 0) ...};

            return stream.str();
        }

        template<typename T>
        std::string toString(T arg) {
            std::ostringstream stream;
            stream << arg;
            return stream.str();
        }

        template<typename T>
        T fromString(const std::string &arg) {
            std::istringstream stream(arg);
            T ret;
            stream >> ret;
            return ret;
        }
    }
}
