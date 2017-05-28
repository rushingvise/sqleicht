
#include "Query.h"
#include "RawQuery.h"
#include "Database.h"

using namespace sqleicht;

Query::~Query() {

}

RawQuery Query::raw_query() {
	return RawQuery();
}

PreparedStatement Query::prepare(Database &db) {
	return PreparedStatement();
}