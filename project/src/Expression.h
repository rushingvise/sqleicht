#pragma once

#include <string>

namespace sqleicht {

    class ExpressionCombiner;
    class ExpressionCore;
	class ExpressionBuilder;

    class Expression {
	public:
		virtual ~Expression(){};

		virtual std::string raw_sql_expression() const;
    };

    class ExpressionCore {
    public:
        virtual ~ExpressionCore() {};

        virtual ExpressionCombiner& column(std::string column_name) =0;
//        ExpressionCombiner literal(int value); // template? traits? probably both
    };

    class ExpressionCombiner : public Expression {
    public:
        virtual ~ExpressionCombiner() {};

//        ExpressionBuilder equals();
//        ExpressionBuilder less_than();
//        ExpressionBuilder less_or_equals();
//        ExpressionBuilder greater_than();
//        ExpressionBuilder greater_or_equals();
//
//        ExpressionBuilder logical_and();
//        ExpressionBuilder logical_or();

    };

	class ExpressionBuilder : public ExpressionCore {
	public:
		virtual ~ExpressionBuilder(){};
	};

	class ExpressionBuilderImpl : public ExpressionBuilder, public ExpressionCombiner {
	public:
		virtual ~ExpressionBuilderImpl(){};

		ExpressionCombiner& column(std::string column_name) override ;

		std::string raw_sql_expression() const override ;
	};

    ExpressionCombiner column(std::string column_name);
}