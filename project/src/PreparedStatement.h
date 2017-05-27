#pragma once

namespace sqleicht {

    class Cursor;

    /**
     * Precompiled SQLite statement ready to be executed.
     */
    class PreparedStatement {
    public:

        virtual ~PreparedStatement();

        template <typename T>
        PreparedStatement& bindValue(unsigned int position, T) {
            return *this;
        }

        Cursor run();
    };

}