#pragma once

#include <string>

#include "sqlite/sqlite3.h"

namespace sqleicht {
    class Database;

    class Error {
    public:
        static int get_result_code();

        static std::string get_error_message();

        static bool has_occurred(int result_code, sqlite3 *db);

    private:
        static void set_result_code(int code);

        static void set_error_message(const std::string &message);

        static int s_result_code;
        static std::string s_error_message;

        friend class Database;
    };
}
