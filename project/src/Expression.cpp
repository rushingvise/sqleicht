#include "Expression.h"

using namespace sqleicht;

ExpressionCombiner sqleicht::column(std::string column_name) {
    return ExpressionBuilderImpl();
}

std::string Expression::raw_sql_expression() const {
    return ""; //dummy
}

ExpressionCombiner & ExpressionBuilderImpl::column(std::string column_name) {
    return *this;
}

std::string ExpressionBuilderImpl::raw_sql_expression() const {
    return "";
}