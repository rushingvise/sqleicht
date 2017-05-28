#include "Query.h"
#include "QueryBuilder.h"
#include "PreparedStatement.h"

using namespace sqleicht;
using namespace std;


QueryBuilder::~QueryBuilder() {

}

//PreparedStatement QueryBuilder::prepare(Database &db) {
//    return PreparedStatement();
//}

Query QueryBuilder::build() {
	return Query(); // pass the builder along
}

QueryBuilder& QueryBuilder::distinct() {
    return *this;
}

QueryBuilder& QueryBuilder::all_columns() {
    return *this;
}

QueryBuilder& QueryBuilder::column(string column_name) {
    return *this;
}

QueryBuilder& QueryBuilder::columns(initializer_list<string> column_name) {
    return *this;
}

QueryBuilder& QueryBuilder::from(string table_name) {
    return *this;
}

QueryBuilder& QueryBuilder::where(Expression &where_clause) {
    return *this;
}

QueryBuilder& QueryBuilder::group_by(Expression &group_expression) {
    return *this;
}

QueryBuilder& QueryBuilder::having(Expression &having_expression) {
    return *this;
}

QueryBuilder & QueryBuilder::order_by(Expression &order_expression) {
    return *this;
}

QueryBuilder & QueryBuilder::order_by(const string &order_expression) {
	return *this;
}

QueryBuilder& QueryBuilder::limit(Expression &limit_expression) {
    return *this;
}

QueryBuilder& QueryBuilder::limit(unsigned int limit) {
	return *this;
}

QueryBuilder& QueryBuilder::limit(unsigned int limit, unsigned int offset) {
	return *this;
}

QueryBuilder &QueryBuilder::group_by(string &group_expression) {
	return *this;
}

QueryBuilder &QueryBuilder::having(string &having_expression) {
	return *this;
}

QueryBuilder &QueryBuilder::order_by(Expression &order_expression, ORDER order) {
	return *this;
}

QueryBuilder &QueryBuilder::order_by(const string &order_expression, ORDER order) {
	return *this;
}

QueryBuilder &QueryBuilder::column(std::string table_name, std::string column_name) {
	return *this;
}


Query CompoundQueryBuilder::build() {
	return Query();
}

QueryBuilder sqleicht::select() {
	QueryBuilder builder;
    return builder;
}

CompoundQueryBuilder sqleicht::select(Query query) {
	return CompoundQueryBuilder();
}

CompoundQueryBuilder sqleicht::select(QueryBuilder query_builder) {
	return CompoundQueryBuilder();
}