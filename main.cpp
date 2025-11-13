#include <iostream>
#include <cstring>

struct Item {
    char* name;
    char* type;
    int level;
};

char* copyString(const char* source) {
    char* copy = new char[strlen(source) + 1];
    strcpy(copy, source);
    return copy;
}

int main() {
    std::cout << "RPG Inventory System" << std::endl;
    return 0;
}
