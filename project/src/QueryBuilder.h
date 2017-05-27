#pragma once

#include "PreparedStatement.h"

#include <string>
#include <initializer_list>

namespace sqleicht {

	class Database;

	class Expression;

	class QueryBuilderColumnResult;

	class QueryBuilder;

	class QueryBuilderFrom;

	class Query;

	class QueryBuilderBase {
	public:
		virtual ~QueryBuilderBase() {};

		virtual PreparedStatement prepare(Database &db) =0;
		virtual Query build() =0;
	};

	class QueryBuilderColumnResult {
	public:
		virtual ~QueryBuilderColumnResult() {};

		virtual QueryBuilderFrom &
		column(std::string column_name) =0; // can be followed by another column, from, where, group by
		virtual QueryBuilderFrom &
		columns(std::initializer_list<std::string> column_name) =0; // can be followed by from, where, group by
		virtual QueryBuilderFrom &all_columns() =0; // can be followed by from, where, group by
	};

	class QueryBuilderDistinct : public virtual QueryBuilderColumnResult {
	public:
		virtual ~QueryBuilderDistinct() {};

		virtual QueryBuilderColumnResult &distinct() =0;
	};

	class QueryBuilderLimit : public virtual QueryBuilderBase {
	public:
		virtual ~QueryBuilderLimit() {};

		virtual QueryBuilderBase &limit(Expression &limit_expression) =0;
		virtual QueryBuilderBase &limit(unsigned int limit) =0;
		virtual QueryBuilderBase &limit(unsigned int limit, unsigned int offset) =0;
	};

	class QueryBuilderOrderDirection;

	class QueryBuilderOrderBy : public virtual QueryBuilderLimit {
	public:
		virtual ~QueryBuilderOrderBy() {};

		virtual QueryBuilderOrderDirection &order_by(Expression &order_expression) =0; // can be followed by direction, another order by or limit
		virtual QueryBuilderOrderDirection &order_by(const std::string &order_expression) =0; // can be followed by direction, another order by or limit
	};

	class QueryBuilderOrderDirection : public virtual QueryBuilderOrderBy {
	public:
		virtual ~QueryBuilderOrderDirection() {};

		virtual QueryBuilderOrderBy &ascending() =0; // can be followed by order by or limit
		virtual QueryBuilderOrderBy &descending() =0; // can be followed by order by or limit

	};

	class QueryBuilderSelectTail : public virtual QueryBuilderOrderBy {
	public:
		virtual ~QueryBuilderSelectTail() {};

	};


	class QueryBuilderHaving : public virtual QueryBuilderBase {
	public:
		virtual ~QueryBuilderHaving() {};

		virtual QueryBuilderSelectTail &having(Expression &having_expression) =0;
	};

	class QueryBuilderGroupBy : public virtual QueryBuilderSelectTail {
	public:
		virtual ~QueryBuilderGroupBy() {};

		virtual QueryBuilderHaving &group_by(Expression &group_expression) =0; //  can be followed by having
	};

	class QueryBuilderWhere : public virtual QueryBuilderGroupBy {
	public:
		virtual ~QueryBuilderWhere() {};

		virtual QueryBuilderGroupBy &where(Expression &where_clause) = 0; // can be followed by group by
	};

	class QueryBuilderFrom : public virtual QueryBuilderWhere {
	public:
		virtual ~QueryBuilderFrom() {};

		virtual QueryBuilderWhere &from(std::string table_name) =0;  // can be followed by where, group by
	};


	class QueryBuilderSelect : public virtual QueryBuilderDistinct {
	public:
		virtual ~QueryBuilderSelect() {};

		// column selector

		QueryBuilderColumnResult &distinct(); // can be followed by column selector only
		QueryBuilderFrom &column(std::string column_name); // can be followed by another column, from, where, group by
		QueryBuilderFrom &
		columns(std::initializer_list<std::string> column_name); // can be followed by from, where, group by
		QueryBuilderFrom &all_columns(); // can be followed by from, where, group by

	};

	// needs to be hidden from the public
	class QueryBuilderImpl
			: public virtual QueryBuilderSelect,
			  public virtual QueryBuilderFrom,
			  public virtual QueryBuilderHaving,
			  public virtual QueryBuilderSelectTail,
			  public virtual QueryBuilderOrderDirection,
			  public virtual QueryBuilderOrderBy,
			  public virtual QueryBuilderBase {
	public:

		virtual ~QueryBuilderImpl();

		PreparedStatement prepare(Database &db) override;

		Query build() override ;

		// column selector

		QueryBuilderColumnResult &distinct() override;

		QueryBuilderFrom &column(std::string column_name) override;

		QueryBuilderFrom &columns(std::initializer_list<std::string> column_name) override;

		QueryBuilderFrom &all_columns() override;

		QueryBuilderWhere &from(std::string table_name) override;

		QueryBuilderGroupBy &where(Expression &where_clause) override ;

		QueryBuilderHaving &group_by(Expression &group_expression) override ;

		QueryBuilderSelectTail &having(Expression &having_expression) override ;

		QueryBuilderOrderDirection & order_by(Expression &order_expression) override ;

		QueryBuilderOrderDirection & order_by(const std::string &order_expression) override ;

		QueryBuilderOrderBy &ascending() override ;

		QueryBuilderOrderBy &descending() override ;

		QueryBuilderBase &limit(Expression &limit_expression) override ;

		QueryBuilderBase &limit(unsigned int limit) override ;

		QueryBuilderBase &limit(unsigned int limit, unsigned int offset) override ;
	};

	QueryBuilderSelect select(); // returns column selector with optional distinct
}