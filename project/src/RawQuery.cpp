#include "RawQuery.h"

using namespace sqleicht;

RawQuery::~RawQuery() {

}

std::string RawQuery::raw_sql_query() {
	return m_query;
}