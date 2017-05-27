#include "Query.h"
#include "QueryBuilder.h"
#include "PreparedStatement.h"

using namespace sqleicht;
using namespace std;

QueryBuilderFrom& QueryBuilderSelect::all_columns() {
    static QueryBuilderImpl builder;
    return builder;
}

QueryBuilderFrom& QueryBuilderSelect::column(std::string column_name) {
    static QueryBuilderImpl builder;
    return builder;
}

QueryBuilderFrom& QueryBuilderSelect::columns(std::initializer_list<std::string> column_name) {
    static QueryBuilderImpl builder;
    return builder;
}

QueryBuilderColumnResult& QueryBuilderSelect::distinct() {
    static QueryBuilderImpl builder;
    return builder;
}


QueryBuilderImpl::~QueryBuilderImpl() {

}

PreparedStatement QueryBuilderImpl::prepare(Database &db) {
    return PreparedStatement();
}

Query QueryBuilderImpl::build() {
	return Query(); // pass the builder along
}

QueryBuilderColumnResult& QueryBuilderImpl::distinct() {
    return *this;
}

QueryBuilderFrom& QueryBuilderImpl::all_columns() {
    return *this;
}

QueryBuilderFrom& QueryBuilderImpl::column(string column_name) {
    return *this;
}

QueryBuilderFrom& QueryBuilderImpl::columns(initializer_list<string> column_name) {
    return *this;
}

QueryBuilderWhere& QueryBuilderImpl::from(string table_name) {
    return *this;
}

QueryBuilderGroupBy& QueryBuilderImpl::where(Expression &where_clause) {
    return *this;
}

QueryBuilderHaving& QueryBuilderImpl::group_by(Expression &group_expression) {
    return *this;
}

QueryBuilderSelectTail& QueryBuilderImpl::having(Expression &having_expression) {
    return *this;
}

QueryBuilderOrderDirection & QueryBuilderImpl::order_by(Expression &order_expression) {
    return *this;
}

QueryBuilderOrderDirection & QueryBuilderImpl::order_by(const string &order_expression) {
	return *this;
}

QueryBuilderOrderBy &QueryBuilderImpl::ascending() {
	return *this;
}

QueryBuilderOrderBy &QueryBuilderImpl::descending() {
	return *this;
}

QueryBuilderBase& QueryBuilderImpl::limit(Expression &limit_expression) {
    return *this;
}

QueryBuilderBase& QueryBuilderImpl::limit(unsigned int limit) {
	return *this;
}

QueryBuilderBase& QueryBuilderImpl::limit(unsigned int limit, unsigned int offset) {
	return *this;
}

QueryBuilderSelect sqleicht::select() {
    QueryBuilderImpl builder;
    return builder;
}