#pragma once


#include "RawQuery.h"
#include "PreparedStatement.h"

namespace sqleicht {

	class Database;

	class Query {
	public:
		virtual ~Query();
		RawQuery raw_query();

		virtual PreparedStatement prepare(Database &db);
	};

}