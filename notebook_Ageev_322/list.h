#include <cstdio>
#pragma once
struct List
{
    char * name;
    unsigned phone_number;
    List * next;
};
List * Find(List * ls, char const * name_to_find);
void Add(List *& ls, char const * new_name, unsigned new_phone);
bool Remove(List *& ls, char const * name_to_delete);
void PrintToFile (List *& ls, FILE * fl);
List * AddvancedFind (List * given_list, const char * name_to_find);
void PrintList(List * ls);