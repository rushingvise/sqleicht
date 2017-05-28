#pragma once

#include <string>

struct TestTable {
	static const std::string TABLE_NAME;
	static const std::string TABLE_NAME_ESCAPED;

	static const std::string COL_1;
	static const std::string COL_1_ESCAPED;
	static const std::string COL_2;
	static const std::string COL_2_ESCAPED;
	static const std::string COL_3;
	static const std::string COL_3_ESCAPED;
};

struct CrazyTable {
	static const std::string TABLE_NAME;
	static const std::string TABLE_NAME_ESCAPED;

	static const std::string COL_CRAZY_QUOTES;
	static const std::string COL_CRAZY_QUOTES_ESCAPED;
};