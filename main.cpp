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

Item* addItem(Item* inv, int& count, const char* name, const char* type, int level) {
    Item* newInv = new Item[count + 1];
    
    for (int i = 0; i < count; i++) {
        newInv[i] = inv[i];
    }
    
    newInv[count].name = copyString(name);
    newInv[count].type = copyString(type);
    newInv[count].level = level;
    
    delete[] inv;
    count++;
    return newInv;
}
