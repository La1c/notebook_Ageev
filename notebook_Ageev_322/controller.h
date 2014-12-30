#include "list.h"
#pragma once

struct DB
{
  List * ls;
};
List * findInDB(DB & mydb, const char *seeked_name);
void addToDB(DB & mydb, const char *new_name, unsigned int new_number);
void findWithMask();
bool deleteFromDB(DB & myDB, const char *name_to_delete);
void dbDown(DB & myDB);
void print(List * ls);