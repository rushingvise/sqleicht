#pragma once

#include <string>
#include "sqlite/sqlite3.h"

namespace sqleicht {

    class Database {
    public:
        enum class Mode : int {
            READ_ONLY = SQLITE_OPEN_READONLY,
            READ_WRITE = SQLITE_OPEN_READWRITE,
            READ_WRITE_CREATE = (SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE)
        };

        Database(const std::string &filename, const Mode &mode = Mode::READ_WRITE_CREATE);

        virtual ~Database();

        bool is_valid() const;

    private:
        sqlite3 *m_db = nullptr;
    };

}
