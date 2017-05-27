
#include "PreparedStatement.h"
#include "Cursor.h"

using namespace sqleicht;

PreparedStatement::~PreparedStatement() {

};

Cursor PreparedStatement::run() {
    return Cursor();
}