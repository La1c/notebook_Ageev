#include "list.h"
List * FindInDB(const char *seeked_name);
void AddToDB(const char *new_name, unsigned int new_number);
void FindWithMask();
bool DeleteFromDB(const char *name_to_delete);
void DBDown();
void Print(List * ls);