#include <cstdio>
#pragma once
struct List
{
  char * name;
  unsigned phone_number;
  List * next;
};
List * find(List * ls, char const * name_to_find);
void add(List *& ls, char const * new_name, unsigned new_phone);
bool remove(List *& ls, char const * name_to_delete);
void printToFile (List *& ls, FILE * fl);
List * wildcardFind (List * given_list, const char * name_to_find);
void printList(List * ls);