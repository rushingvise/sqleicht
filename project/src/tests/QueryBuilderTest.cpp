#include "Database.h"
#include "Query.h"
#include "QueryBuilder.h"
#include "Expression.h"
#include "gtest/gtest.h"
#include "TestTable.h"

#include <string>

using namespace sqleicht;

const std::string TestTable::TABLE_NAME = "test";
const std::string TestTable::TABLE_NAME_ESCAPED = "\"test\"";

const std::string TestTable::COL_1 = "idx";
const std::string TestTable::COL_1_ESCAPED = "\"idx\"";

const std::string TestTable::COL_2 = "val";
const std::string TestTable::COL_2_ESCAPED = "\"val\"";

const std::string TestTable::COL_3 = "dsc";
const std::string TestTable::COL_3_ESCAPED = "\"dsc\"";

const std::string CrazyTable::TABLE_NAME = "ciach/\"'`trach";
const std::string CrazyTable::TABLE_NAME_ESCAPED = "\"ciach/\"\"'`trach\"";
const std::string CrazyTable::COL_CRAZY_QUOTES = "'this' is a \"valid\"`column` [name]";
const std::string CrazyTable::COL_CRAZY_QUOTES_ESCAPED = "\"'this' is a \"\"valid\"\"`column` [name]\"";

class QueryBuilderTest : public ::testing::Test {

};

TEST_F(QueryBuilderTest, selectAllColumns) {
	RawQuery raw_query = select()
			.all_columns()
			.from(TestTable::TABLE_NAME)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(), "SELECT * FROM " + TestTable::TABLE_NAME_ESCAPED + ";");
}

TEST_F(QueryBuilderTest, selectSingleColumn) {
	RawQuery raw_query = select()
			.column(TestTable::COL_1)
			.from(TestTable::TABLE_NAME)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(),
			  "SELECT " + TestTable::COL_1_ESCAPED
			  + " FROM " + TestTable::TABLE_NAME_ESCAPED + ";");
}

TEST_F(QueryBuilderTest, selectManyColumnsWithSingle) {
	RawQuery raw_query = select()
			.column(TestTable::COL_1)
			.column(TestTable::COL_2)
			.column(TestTable::COL_3)
			.from(TestTable::TABLE_NAME)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(),
			  "SELECT " + TestTable::COL_1_ESCAPED + "," + TestTable::COL_2_ESCAPED + "," + TestTable::COL_3_ESCAPED
			  + " FROM " + TestTable::TABLE_NAME_ESCAPED + ";");
}

TEST_F(QueryBuilderTest, selectSingleColumnWithTableName) {
	RawQuery raw_query = select()
			.column(TestTable::TABLE_NAME, TestTable::COL_1)
			.from(TestTable::TABLE_NAME)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(),
			  "SELECT " + TestTable::TABLE_NAME_ESCAPED + "." + TestTable::COL_1_ESCAPED
			  + " FROM " + TestTable::TABLE_NAME_ESCAPED + ";");
}

TEST_F(QueryBuilderTest, selectSingleColumnWithList) {
	RawQuery raw_query = select()
			.columns({TestTable::COL_1})
			.from(TestTable::TABLE_NAME)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(),
			  "SELECT " + TestTable::COL_1_ESCAPED
			  + " FROM " + TestTable::TABLE_NAME_ESCAPED + ";");
}

TEST_F(QueryBuilderTest, selectMultipleColumnsWithList) {
	RawQuery raw_query = select()
			.columns({TestTable::COL_1, TestTable::COL_2, TestTable::COL_3})
			.from(TestTable::TABLE_NAME)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(),
			  "SELECT " + TestTable::COL_1_ESCAPED + "," + TestTable::COL_2_ESCAPED + "," + TestTable::COL_3_ESCAPED
			  + " FROM " + TestTable::TABLE_NAME_ESCAPED + ";");
}

TEST_F(QueryBuilderTest, columnNameEscaping) {
	RawQuery raw_query = select()
			.column(CrazyTable::COL_CRAZY_QUOTES)
			.from(CrazyTable::TABLE_NAME)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(),
			  "SELECT " + CrazyTable::COL_CRAZY_QUOTES_ESCAPED
			  + " FROM " + CrazyTable::TABLE_NAME_ESCAPED + ";");
}

TEST_F(QueryBuilderTest, selectManyColumnsMixed) {
	RawQuery raw_query = select()
			.column(TestTable::TABLE_NAME,TestTable::COL_1)
			.column(TestTable::COL_2)
			.columns({TestTable::COL_3})
			.from(TestTable::TABLE_NAME)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(),
			  "SELECT " + TestTable::TABLE_NAME_ESCAPED + "." + TestTable::COL_1_ESCAPED
					  + "," + TestTable::COL_2_ESCAPED + "," + TestTable::COL_3_ESCAPED
			  + " FROM " + TestTable::TABLE_NAME_ESCAPED + ";");
}

TEST_F(QueryBuilderTest, selectOrderByColumnLiteral) {
	RawQuery raw_query = select()
			.all_columns()
			.from(TestTable::TABLE_NAME)
			.order_by(TestTable::COL_1)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(),
			  "SELECT * FROM " + TestTable::TABLE_NAME_ESCAPED
			  + " ORDER BY " + TestTable::COL_1_ESCAPED + ";");
}

TEST_F(QueryBuilderTest, selectOrderByColumnExpressionSingle) {
	Expression order_expr = column(TestTable::COL_1);
	RawQuery raw_query = select()
			.all_columns()
			.from(TestTable::TABLE_NAME)
			.order_by(order_expr)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(),
			  "SELECT * FROM " + TestTable::TABLE_NAME_ESCAPED
			  + " ORDER BY " + TestTable::COL_1_ESCAPED + ";");
}

TEST_F(QueryBuilderTest, selectOrderByColumnExpressionSingleAscending) {
	Expression order_expr = column(TestTable::COL_1);
	RawQuery raw_query = select()
			.all_columns()
			.from(TestTable::TABLE_NAME)
			.order_by(order_expr, ORDER::ASCENDING)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(),
			  "SELECT * FROM " + TestTable::TABLE_NAME_ESCAPED
			  + " ORDER BY " + TestTable::COL_1_ESCAPED + " ASC;");
}

TEST_F(QueryBuilderTest, selectOrderByColumnExpressionSingleDescending) {
	Expression order_expr = column(TestTable::COL_1);
	RawQuery raw_query = select()
			.all_columns()
			.from(TestTable::TABLE_NAME)
			.order_by(order_expr, ORDER::DESCENDING)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(),
			  "SELECT * FROM " + TestTable::TABLE_NAME_ESCAPED
			  + " ORDER BY " + TestTable::COL_1_ESCAPED + " DESC;");
}

TEST_F(QueryBuilderTest, selectLimitByLiteral) {
	RawQuery raw_query = select()
			.all_columns()
			.from(TestTable::TABLE_NAME)
			.limit(2)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(),
			  "SELECT * FROM " + TestTable::TABLE_NAME_ESCAPED
			  + " LIMIT " + TestTable::COL_1_ESCAPED + "\";");
}

TEST_F(QueryBuilderTest, selectUnionFromQueryVar) {
	Query query_1 = select().all_columns().from(TestTable::TABLE_NAME).build();
	Query query_2 = select().all_columns().from(CrazyTable::TABLE_NAME).build();

	RawQuery raw_query = select(
				query_1
			).union_with(query_2)
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(),
			  "SELECT * FROM " + TestTable::TABLE_NAME_ESCAPED
			  + " UNION "
			  + "SELECT * FROM " + CrazyTable::TABLE_NAME_ESCAPED + ";");
}

TEST_F(QueryBuilderTest, selectUnionFromQuery) {
	RawQuery raw_query = select(
				select().all_columns().from(TestTable::TABLE_NAME).build()
			).union_with(select().all_columns().from(CrazyTable::TABLE_NAME).build())
			.build().raw_query();

	ASSERT_EQ(raw_query.raw_sql_query(),
			  "SELECT * FROM " + TestTable::TABLE_NAME_ESCAPED
			  + " UNION "
			  + "SELECT * FROM " + CrazyTable::TABLE_NAME_ESCAPED + ";");
}