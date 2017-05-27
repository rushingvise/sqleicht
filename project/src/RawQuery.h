#pragma once

#include <string>
#include <vector>

namespace sqleicht {

    /**
     * Encapsulates SQLite query and its arguments.
     */
    class RawQuery {
    public:

        virtual ~RawQuery();

		std::string raw_sql_query();

	private:
		std::string m_query;
		std::vector<std::string> m_query_args;

    };
}

