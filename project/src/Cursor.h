#pragma once

#include <string>
#include <vector>

namespace sqleicht {

    class Cursor {
    public:

        ~Cursor();

        void close();
        bool is_closed();

        int column_count();

        std::string column_name(int column_index);

        std::vector<std::string> column_names();

    };

}