
#include "Query.h"
#include "RawQuery.h"
using namespace sqleicht;

Query::~Query() {

}

RawQuery Query::raw_query() {
	return RawQuery();
}