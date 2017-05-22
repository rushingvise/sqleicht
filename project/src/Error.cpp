#include "Error.h"
#include "StringUtils.h"

using namespace sqleicht;

std::string Error::get_error_message() {
    return s_error_message;
}

void Error::set_error_message(const std::string &message) {
    s_error_message = message;
}

int Error::get_result_code() {
    return s_result_code;
}

void Error::set_result_code(int code) {
    s_result_code = code;
}

bool Error::has_occurred(int result_code, sqlite3 *db) {
    if (result_code != SQLITE_OK) {
        set_result_code(result_code);
        set_error_message(StringUtils::concatenate(sqlite3_errmsg(db), '(', result_code, ")."));
        return true;
    }
    return false;
}

int Error::s_result_code = SQLITE_OK;
std::string Error::s_error_message;
