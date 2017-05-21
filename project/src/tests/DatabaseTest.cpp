#include "Database.h"
#include "gtest/gtest.h"

class DatabaseTest : public ::testing::Test {
protected:
    // You can define per-test set-up and tear-down logic as usual.
    virtual void SetUp() {
        database = new sqleicht::Database();
    }

    virtual void TearDown() {
        delete database;
    }

    // Some expensive resource shared by all tests.
    sqleicht::Database *database;
};

TEST_F(DatabaseTest, dummyTrue) {
    EXPECT_TRUE(database->dummyTrue());
}

TEST_F(DatabaseTest, dummyFalse) {
    EXPECT_FALSE(database->dummyFalse());
}
