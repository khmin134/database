#include "../inc/cmd.h"

void add_item(Database& db) {
    std::string key = "", type = "";

    std::cout << "key: ";
    std::cin >> key;
    std::cout << "type (int, double, string, array): ";
    std::cin >> type;

    if(type == "int")
        add(db, create(Type::INT, key, make_int()));
    else if(type == "double")
        add(db, create(Type::DOUBLE, key, make_double()));
    else if(type == "string")
        add(db, create(Type::STRING, key, make_string()));
    else if(type == "array");
        //add(db, create(Type::ARRAY, key, make_array()));
}

int* make_int() {
    int* value = new int;

    std::cout << "value: ";
    std::cin >> *value;
    return value;
}

double* make_double() {
    double* value = new double;

    std::cout << "value: ";
    std::cin >> *value;
    return value;
}

std::string* make_string() {
    std::string* value = new std::string;

    std::cin.ignore();

    std::cout << "value: ";
    std::getline(std::cin, *value);
    value->insert(0, "\"");
    return value;
}

Array* make_array() {
    std::string type = "";
    int sz = 0;

    std::cout << "size: ";
    std::cin >> sz;
    std::cout << "type (int, double, string, array): ";
    std::cin >> type;

    Array* ary = new Array;
    ary->size = sz;

    if(type == "int") {
        ary->items = new int[sz];

        for(int i = 0; i < sz; i++) {
            std::cout << "item[" << i << "]: ";
            std::cin >> *((int*)(ary->items)+i);
        }
    } else if(type == "double") {
        ary->items = new double[sz];

        for(int i = 0; i < sz; i++) {
            std::cout << "item[" << i << "]: ";
            std::cin >> *((double*)(ary->items)+i);
        }
    } else if(type == "string") {
        ary->items = new std::string[sz];
        std::cin.ignore();

        for(int i = 0; i < sz; i++) {
            std::cout << "item[" << i << "]: ";
            std::getline(std::cin, *((std::string*)(ary->items)+i));
        }
    } else if(type == "array") {
        ary->items = new Array[sz];
        Array* item = (Array*)ary->items;

        for(int i = 0; i < sz; i++, item++) {
            item = make_array();
        }
    }

    return ary;
}

void get_item(Database& db) {
    std::string key = "";

    std::cout << "key: ";
    std::cin >> key;

    std::cout << key << ": ";
    auto p = get(db, key);

    switch(p->type) {
    case Type::INT:
        std::cout << *(int*)p->value << std::endl;
        break;

    case Type::DOUBLE:
        std::cout << *(double*)p->value << std::endl;
        break;

    case Type::STRING:
        std::cout << *(std::string*)p->value << std::endl;
        break;


    }
}

void del_item(Database& db) {
    std::string key = "";

    std::cout << "key: ";
    std::cin >> key;

    remove(db, key);
}
