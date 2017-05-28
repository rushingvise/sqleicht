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

Query QueryBuilder::build() const {
	return Query();
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

QueryBuilder& QueryBuilder::column(std::string table_name, std::string column_name) {
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

CompoundQueryBuilder::~CompoundQueryBuilder() {

}

Query CompoundQueryBuilder::build() const {
	return Query();
}

CompoundQueryBuilder &CompoundQueryBuilder::limit(Expression &limit_expression) {
	return *this;
}

CompoundQueryBuilder &CompoundQueryBuilder::limit(unsigned int limit) {
	return *this;
}

CompoundQueryBuilder &CompoundQueryBuilder::limit(unsigned int limit, unsigned int offset) {
	return *this;
}

CompoundQueryBuilder &CompoundQueryBuilder::order_by(Expression &order_expression) {
	return *this;
}

CompoundQueryBuilder &CompoundQueryBuilder::order_by(const std::string &order_expression) {
	return *this;
}

CompoundQueryBuilder &CompoundQueryBuilder::order_by(Expression &order_expression, ORDER order) {
	return *this;
}

CompoundQueryBuilder &CompoundQueryBuilder::order_by(const std::string &order_expression, ORDER order) {
	return *this;
}

CompoundQueryBuilder &CompoundQueryBuilder::union_with(const Query &query) {
	return *this;
}

CompoundQueryBuilder &CompoundQueryBuilder::union_with(QueryBuilder &query_builder) {
	return *this;
}

CompoundQueryBuilder &CompoundQueryBuilder::union_all(const Query &query) {
	return *this;
}

CompoundQueryBuilder &CompoundQueryBuilder::union_all(QueryBuilder &queryBuilder) {
	return *this;
}

CompoundQueryBuilder &CompoundQueryBuilder::intersect(const Query &query) {
	return *this;
}

CompoundQueryBuilder &CompoundQueryBuilder::intersect(QueryBuilder &queryBuilder) {
	return *this;
}

CompoundQueryBuilder &CompoundQueryBuilder::except(const Query &query) {
	return *this;
}

CompoundQueryBuilder &CompoundQueryBuilder::except(QueryBuilder &queryBuilder) {
	return *this;
}

QueryBuilder sqleicht::select() {
	QueryBuilder builder;
    return builder;
}

CompoundQueryBuilder sqleicht::select(const Query &query) {
	return CompoundQueryBuilder();
}

CompoundQueryBuilder sqleicht::select(QueryBuilder &query_builder) {
	return CompoundQueryBuilder();
}