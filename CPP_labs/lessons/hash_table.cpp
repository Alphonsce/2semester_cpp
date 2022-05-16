#include <iostream>
#include <list>
#include <vector>

unsigned int hash(unsigned int x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

// table is represented by array of head elements
struct Table {
    std::vector<std::list<int> > table; // массив из связных списков
    std::size_t size;
};

// creates empty hash_table
Table new_table(std::size_t size) {
    std::list<int> l;
    std::vector<std::list<int> > table {size, l};
    return Table {table, size};
}

void erase_table(Table& hash_table) {
    for (int i = 0; i < hash_table.size; i++) {
        hash_table.table[i].clear();
    }
}

void add_element(Table& hash_table, int value) {
    bool found = false;
    unsigned int idx = hash(value) % hash_table.size;
    std::list<int> l = hash_table.table[idx];

    if (!found)
        hash_table.table[idx].push_back(value);
}

void print_list(std::list<int> l) {
    if ((l.empty())) {
        std::cout << "NULL";
    }
    for (std::list<int>::iterator i = l.begin(); i != l.end(); ++i) {
        std::cout << *i << " -> ";
    }
    std::cout << std::endl;
}

void print_table(Table hash_table) {
    for (std::size_t i = 0; i < hash_table.size; i ++) {
        print_list(hash_table.table[i]);
        // std::cout << hash_table.table[i].empty() << std::endl;
    }
}

int main() {
    Table hash_table = new_table(8);
    for (int i = 0; i < 50; i ++)
        add_element(hash_table, i);

    print_table(hash_table);
    erase_table(hash_table);
    std::cout << "-------------" << std::endl;

    add_element(hash_table, 5);
    add_element(hash_table, 6);
    print_table(hash_table);

    return 0;
}