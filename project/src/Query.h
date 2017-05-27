#pragma once


#include "RawQuery.h"

namespace sqleicht {

	class Query {
	public:
		virtual ~Query();
		RawQuery raw_query();
	};

}