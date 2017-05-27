#include "Database.h"
#include "Query.h"
#include "QueryBuilder.h"
#include "Expression.h"
#include "gtest/gtest.h"

TEST(DatabaseTest, failsOnOpeningNonExistingDatabase) {
    sqleicht::Database db("nonexisting.db", sqleicht::Database::Mode::READ_ONLY);
    ASSERT_FALSE(db.is_valid());
}

TEST(DatabaseTest, succeedsOnCreatingDatabase) {
    sqleicht::Database db("created.db", sqleicht::Database::Mode::READ_WRITE_CREATE);
    ASSERT_TRUE(db.is_valid());
}
