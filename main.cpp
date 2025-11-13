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

void sortByLevel(Item* inv, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (inv[j].level > inv[j + 1].level) {
                Item temp = inv[j];
                inv[j] = inv[j + 1];
                inv[j + 1] = temp;
            }
        }
    }
}

Item* filterByType(Item* inv, int count, const char* type, int& resultCount) {
    resultCount = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(inv[i].type, type) == 0) {
            resultCount++;
        }
    }
    
    if (resultCount == 0) return nullptr;
    
    Item* filtered = new Item[resultCount];
    int index = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(inv[i].type, type) == 0) {
            filtered[index].name = copyString(inv[i].name);
            filtered[index].type = copyString(inv[i].type);
            filtered[index].level = inv[i].level;
            index++;
        }
    }
    
    return filtered;
}

void freeInventory(Item* inv, int count) {
    for (int i = 0; i < count; i++) {
        delete[] inv[i].name;
        delete[] inv[i].type;
    }
    delete[] inv;
}
