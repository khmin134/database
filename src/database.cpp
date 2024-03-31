#include <iostream>
#include <string>
#include "../inc/database.h"

Entry *create(Type type, std::string key, void *value) {
    return new Entry {
        type, key, value
    };
}

// 데이터베이스를 초기화한다.
void init(Database &database) {
    database.data = new Entry*[DEFAULT_DB_CAP];
    database.cap = DEFAULT_DB_CAP;
    database.pos = 0;
}

// 데이터베이스에 엔트리를 추가한다.
void add(Database &database, Entry *entry) {
    if(database.cap <= database.pos) {
        database.cap *= 2;
        Entry** temp = new Entry*[database.cap];

        for(size_t i = 0; i < database.pos; i++)
            temp[i] = database.data[i];

        delete[] database.data;
        database.data = temp;
    }

    database.data[database.pos++] = entry;
}

// 데이터베이스에서 키에 해당하는 엔트리를 찾는다.
Entry *get(Database &database, std::string &key) {
    for(size_t i = 0; i < database.pos; i++) {
        if(database.data[i]->key == key)
            return database.data[i];
    }

    return nullptr;
}

// 데이터베이스에서 키에 해당하는 엔트리를 제거한다.
void remove(Database &database, std::string &key) {
    for(size_t i = 0; i < database.pos; i++) {
        if(database.data[i]->key == key) {
            delete database.data[i];

            for(size_t j = i; j < database.pos-1; j++) {
                database.data[j] = database.data[j+1];
            }

            return;
        }
    }
}

// 데이터베이스를 해제한다.
void destroy(Database &database) {
    for(size_t i = 0; i < database.pos; i++) {
        delete database.data[i];
    }

    delete[] database.data;
    database.cap = 0;
    database.pos = 0;
}

