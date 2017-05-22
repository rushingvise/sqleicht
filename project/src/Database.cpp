#include "Database.h"
#include "Error.h"

using namespace sqleicht;

Database::Database(const std::string& filename, const Mode& mode) {
    int rc = sqlite3_open_v2(filename.c_str(), &m_db, static_cast<int>(mode), nullptr);
    if (Error::has_occurred(rc, m_db)) {
        // Failure!
        sqlite3_close(m_db);
        m_db = nullptr;
    }
}

Database::~Database() {
    if (is_valid()) {
        sqlite3_close(m_db);
        m_db = nullptr;
    }
}

bool Database::is_valid() const {
    return m_db != nullptr;
}
