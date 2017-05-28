#pragma once

#include "PreparedStatement.h"

#include <string>
#include <initializer_list>

namespace sqleicht {

	class Database;
	class Expression;
	class QueryBuilder;
	class CompoundQueryBuilder;
	class Query;

	enum class ORDER : uint8_t {
		ASCENDING,
		DESCENDING
	};

	class QueryBuilderBase {
	public:
		virtual ~QueryBuilderBase() {};

//		virtual PreparedStatement prepare(Database &db) =0;
		virtual Query build() const =0;
	};

	class DistinctSelector {
	public:
		virtual ~DistinctSelector() {};

		virtual QueryBuilder &distinct() =0;

		// we can skip ALL since it should be fairly obvious it is the default
	};

	class LimitBuilder {
	public:
		virtual ~LimitBuilder() {};

		virtual QueryBuilder &limit(Expression &limit_expression) =0;
		virtual QueryBuilder &limit(unsigned int limit) =0;
		virtual QueryBuilder &limit(unsigned int limit, unsigned int offset) =0;
	};

	class OrderByBuilder {
	public:
		virtual ~OrderByBuilder() {};

		virtual QueryBuilder &order_by(Expression &order_expression) =0; // can be followed by direction, another order by or limit
		virtual QueryBuilder &order_by(const std::string &order_expression) =0; // can be followed by direction, another order by or limit

		virtual QueryBuilder &order_by(Expression &order_expression, ORDER order) =0;
		virtual QueryBuilder &order_by(const std::string &order_expression, ORDER order) =0;
	};

	class HavingBuilder {
	public:
		virtual ~HavingBuilder() {};

		virtual QueryBuilder &having(Expression &having_expression) =0;
		virtual QueryBuilder &having(std::string &having_expression) =0;
	};

	class GroupByBuilder {
	public:
		virtual ~GroupByBuilder() {};

		virtual QueryBuilder &group_by(Expression &group_expression) =0;
		virtual QueryBuilder &group_by(std::string &group_expression) =0;
	};

	class WhereBuilder {
	public:
		virtual ~WhereBuilder() {};

		virtual QueryBuilder &where(Expression &where_clause) = 0; // can be followed by group by
	};

	class TableSelector {
	public:
		virtual ~TableSelector() {};

		virtual QueryBuilder &from(std::string table_name) =0;  // can be followed by where, group by

		//TODO add support for subquery
	};


	class ColumnSelector {
	public:
		virtual ~ColumnSelector() {};

		virtual QueryBuilder &column(std::string column_name) =0;

		virtual QueryBuilder &column(std::string table_name, std::string column_name) =0;

		virtual QueryBuilder &
		columns(std::initializer_list<std::string> column_name) =0;

		virtual QueryBuilder &all_columns() =0;

	};

	class QueryBuilder
			: public QueryBuilderBase,
			  public TableSelector,
			  public DistinctSelector,
			  public ColumnSelector,
			  public WhereBuilder,
			  public GroupByBuilder,
			  public HavingBuilder,
			  public OrderByBuilder,
			  public LimitBuilder {
	public:

		virtual ~QueryBuilder();

//		PreparedStatement prepare(Database &db) override;

		Query build() const override ;

		QueryBuilder &distinct() override;

		QueryBuilder &column(std::string column_name) override;

		QueryBuilder &column(std::string table_name, std::string column_name) override ;

		QueryBuilder &columns(std::initializer_list<std::string> column_name) override;

		QueryBuilder &all_columns() override;

		QueryBuilder &from(std::string table_name) override;

		QueryBuilder &where(Expression &where_clause) override ;

		QueryBuilder &group_by(Expression &group_expression) override ;

		QueryBuilder &having(Expression &having_expression) override ;

		QueryBuilder & order_by(Expression &order_expression) override ;

		QueryBuilder & order_by(const std::string &order_expression) override ;

		QueryBuilder &limit(Expression &limit_expression) override ;

		QueryBuilder &limit(unsigned int limit) override ;

		QueryBuilder &limit(unsigned int limit, unsigned int offset) override ;

		QueryBuilder &group_by(std::string &group_expression) override;

		QueryBuilder &having(std::string &having_expression) override;

		QueryBuilder &order_by(Expression &order_expression, ORDER order) override;

		QueryBuilder &order_by(const std::string &order_expression, ORDER order) override;

	};

	class CompoundLimitBuilder {
	public:
		virtual ~CompoundLimitBuilder() {};

		virtual CompoundQueryBuilder &limit(Expression &limit_expression) =0;
		virtual CompoundQueryBuilder &limit(unsigned int limit) =0;
		virtual CompoundQueryBuilder &limit(unsigned int limit, unsigned int offset) =0;
	};

	class CompoundOrderByBuilder {
	public:
		virtual ~CompoundOrderByBuilder() {};

		virtual CompoundQueryBuilder &order_by(Expression &order_expression) =0; // can be followed by direction, another order by or limit
		virtual CompoundQueryBuilder &order_by(const std::string &order_expression) =0; // can be followed by direction, another order by or limit

		virtual CompoundQueryBuilder &order_by(Expression &order_expression, ORDER order) =0;
		virtual CompoundQueryBuilder &order_by(const std::string &order_expression, ORDER order) =0;
	};

	class CompoundQueryBuilder
			: public QueryBuilderBase,
			  public CompoundLimitBuilder,
			  public CompoundOrderByBuilder {
	public:

		virtual ~CompoundQueryBuilder();

		Query build() const override ;

		CompoundQueryBuilder &limit(Expression &limit_expression) override;

		CompoundQueryBuilder &limit(unsigned int limit) override;

		CompoundQueryBuilder &limit(unsigned int limit, unsigned int offset) override;

		CompoundQueryBuilder &order_by(Expression &order_expression) override;

		CompoundQueryBuilder &order_by(const std::string &order_expression) override;

		CompoundQueryBuilder &order_by(Expression &order_expression, ORDER order) override;

		CompoundQueryBuilder &order_by(const std::string &order_expression, ORDER order) override;

		CompoundQueryBuilder &union_with(const Query &query);
		CompoundQueryBuilder &union_with(QueryBuilder &query_builder);

		CompoundQueryBuilder &union_all(const Query &query);
		CompoundQueryBuilder &union_all(QueryBuilder &queryBuilder);

		CompoundQueryBuilder &intersect(const Query &query);
		CompoundQueryBuilder &intersect(QueryBuilder &queryBuilder);

		CompoundQueryBuilder &except(const Query &query);
		CompoundQueryBuilder &except(QueryBuilder &queryBuilder);

	};

	QueryBuilder select();

	CompoundQueryBuilder select(const Query &query);

	CompoundQueryBuilder select(QueryBuilder &query_builder);
}