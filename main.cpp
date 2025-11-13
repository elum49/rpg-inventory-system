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

void printInventory(Item* inv, int count) {
    std::cout << "Инвентарь (" << count << "):\n";
    for (int i = 0; i < count; i++) {
        std::cout << "- " << inv[i].name << " [" << inv[i].type 
                  << "] ур." << inv[i].level << "\n";
    }
}

Item* removeItem(Item* inv, int& count, const char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(inv[i].name, name) == 0) {
            Item* newInv = new Item[count - 1];
            
            for (int j = 0; j < i; j++) {
                newInv[j] = inv[j];
            }
            for (int j = i + 1; j < count; j++) {
                newInv[j - 1] = inv[j];
            }
            
            delete[] inv[i].name;
            delete[] inv[i].type;
            delete[] inv;
            
            count--;
            return newInv;
        }
    }
    return inv;
}
