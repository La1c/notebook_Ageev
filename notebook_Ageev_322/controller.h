#include "list.h"
List * findInDB(const char *seeked_name);
void addToDB(const char *new_name, unsigned int new_number);
void findWithMask();
bool deleteFromDB(const char *name_to_delete);
void dbDown();
void print(List * ls);