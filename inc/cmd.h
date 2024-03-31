#ifndef CMD_H
#define CMD_H

#include <string>
#include <iostream>
#include "database.h"

void add_item(Database& db);
int* make_int();
double* make_double();
std::string* make_string();
Array* make_array();
void get_item(Database& db);
void del_item(Database& db);

#endif
