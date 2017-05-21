#include <iostream>
#include "Database.h"

int main() {
    sqleicht::Database db;
    std::cout << "Hello, World! " << db.dummyTrue() << std::endl;
    return 0;
}