#include "Database.h"
#include "Query.h"
#include "QueryBuilder.h"
#include "Expression.h"
#include "gtest/gtest.h"
#include "TestTable.h"

#include <string>

using namespace sqleicht;

const std::string TestTable::TABLE_NAME = "test";
const std::string TestTable::COL_1 = "idx";
const std::string TestTable::COL_2 = "val";
const std::string TestTable::COL_3 = "dsc";
const std::string TestTable::COL_CRAZY_QUOTES = "'this' is a \"valid\"`column` [name]";
const std::string TestTable::COL_CRAZY_QUOTES_ESCAPED = "'this' is a \"\"valid\"\"`column` [name]";

class QueryBuilderTest : public ::testing::Test {

};

TEST_F(QueryBuilderTest, selectAllColumns) {
	RawQuery raw_query = select()
			.all_columns()
			.from(TestTable::TABLE_NAME)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(), "SELECT * FROM \"" + TestTable::TABLE_NAME + "\";");
}

TEST_F(QueryBuilderTest, selectSingleColumn) {
	RawQuery raw_query = select()
			.column(TestTable::COL_1)
			.from(TestTable::TABLE_NAME)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(), "SELECT \"" + TestTable::COL_1 + "\" FROM \"" + TestTable::TABLE_NAME + "\";");
}

TEST_F(QueryBuilderTest, selectSingleColumnList) {
	RawQuery raw_query = select()
			.columns({TestTable::COL_1})
			.from(TestTable::TABLE_NAME)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(), "SELECT \"" + TestTable::COL_1 + "\" FROM \"" + TestTable::TABLE_NAME + "\";");
}

TEST_F(QueryBuilderTest, selectMultipleColumnsList) {
	RawQuery raw_query = select()
			.columns({TestTable::COL_1, TestTable::COL_2, TestTable::COL_3})
			.from(TestTable::TABLE_NAME)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(),
			  "SELECT \"" + TestTable::COL_1 + "\",\"" + TestTable::COL_2 + "\",\"" + TestTable::COL_3
			  + "\" FROM \"" + TestTable::TABLE_NAME + "\";");
}

TEST_F(QueryBuilderTest, columnNameEscaping) {
	RawQuery raw_query = select()
			.column(TestTable::COL_CRAZY_QUOTES)
			.from(TestTable::TABLE_NAME)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(), "SELECT \"" + TestTable::COL_CRAZY_QUOTES_ESCAPED + "\" FROM \"" + TestTable::TABLE_NAME + "\";");
}

TEST_F(QueryBuilderTest, selectOrderByColumnLiteral) {
	RawQuery raw_query = select()
			.all_columns()
			.from(TestTable::TABLE_NAME)
			.order_by(TestTable::COL_1)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(), "SELECT * FROM " + TestTable::TABLE_NAME + " ORDER BY \"" + TestTable::COL_1 + "\";");
}

TEST_F(QueryBuilderTest, selectOrderByColumnExpressionSingle) {
	Expression order_expr = column(TestTable::COL_1);
	RawQuery raw_query = select()
			.all_columns()
			.from(TestTable::TABLE_NAME)
			.order_by(order_expr)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(), "SELECT * FROM " + TestTable::TABLE_NAME + " ORDER BY \"" + TestTable::COL_1 + "\";");
}

TEST_F(QueryBuilderTest, selectOrderByColumnExpressionSingleAscending) {
	Expression order_expr = column(TestTable::COL_1);
	RawQuery raw_query = select()
			.all_columns()
			.from(TestTable::TABLE_NAME)
			.order_by(order_expr)
			.ascending()
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(), "SELECT * FROM " + TestTable::TABLE_NAME + " ORDER BY \"" + TestTable::COL_1 + "\" ASC;");
}

TEST_F(QueryBuilderTest, selectOrderByColumnExpressionSingleDescending) {
	Expression order_expr = column(TestTable::COL_1);
	RawQuery raw_query = select()
			.all_columns()
			.from(TestTable::TABLE_NAME)
			.order_by(order_expr)
			.descending()
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(), "SELECT * FROM " + TestTable::TABLE_NAME + " ORDER BY \"" + TestTable::COL_1 + "\" DESC;");
}

TEST_F(QueryBuilderTest, selectLimitByLiteral) {
	RawQuery raw_query = select()
			.all_columns()
			.from(TestTable::TABLE_NAME)
			.limit(2)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(), "SELECT * FROM " + TestTable::TABLE_NAME + " LIMIT \"" + TestTable::COL_1 + "\";");
}