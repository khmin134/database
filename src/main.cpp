#include <iostream>
#include <string>
#include "../inc/database.h"
#include "../inc/cmd.h"

void list_array(const Array* ary) {
    std::cout << "[";
   
    for(int i = 0; i < ary->size; i++) {
        switch(ary->type) {
        case Type::INT:
            std::cout << *((int*)(ary->items)+i) << " ";
            break;
        case Type::DOUBLE:
            std::cout << *((double*)(ary->items)+i) << " "; 
            break;
        case Type::STRING:
            std::cout << *((std::string*)(ary->items)+i) << " ";
            break;
        case Type::ARRAY:
            list_array((Array*)(ary->items)+i);
            break;
        }
    }

    std::cout << "]";
}

void list(const Database& db) {
    for(size_t i = 0; i < db.pos; i++) {
        switch(db.data[i]->type) {
        case Type::INT:
            std::cout << db.data[i]->key << ": " << *(int*)db.data[i]->value << std::endl;
            break;
        case Type::DOUBLE:
            std::cout << db.data[i]->key << ": " << *(double*)db.data[i]->value << std::endl;
            break;
        case Type::STRING:
            std::cout << db.data[i]->key << ": " <<*(std::string*)db.data[i]->value << std::endl;
            break;
        case Type::ARRAY:
            list_array((Array*)db.data[i]->value);
            std::cout << std::endl;
            break;
        }
    }
}

int main() {
    Database db;

    init(db);

    while(true) {
        std::string input = "";

        std::cout << "command (list, add, get, del, exit): ";
        std::cin >> input;

        if(input == "list") list(db);
        else if(input == "add") add_item(db);
        else if(input == "get") get_item(db);
        else if(input == "del") del_item(db);
        else if(input == "exit") break;
        else std::cout << "Unknown command!" << std::endl;
    }
}
