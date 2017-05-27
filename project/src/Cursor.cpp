#include "Cursor.h"

using namespace sqleicht;
using namespace std;

Cursor::~Cursor() {

}

void Cursor::close() {

}

bool Cursor::is_closed() {
    return true;
}

int Cursor::column_count() {
    return 0;
}

std::string Cursor::column_name(int column_index) {
    return "";
}

std::vector<std::string> Cursor::column_names() {
    return vector<string>();
}