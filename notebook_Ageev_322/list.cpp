/*#include "list.h"
#include <ctype.h>
#include <string.h>
#include <map>
#include <string>
#include <fstream>
using std::string;
using std::map;

//DB entry -- List is defined in the .h file


bool checkMask(const char * str_with_mask, const char * str_to_check)
{
  if (strlen(str_with_mask) == strlen(str_to_check))
  {
    while (*str_with_mask)
    {
      if (*str_with_mask != '?' && *str_with_mask != *str_to_check)
      {
        return false;
      }
      str_with_mask++;
      str_to_check++;
    }
    return true;
  }
  return false;
}

List * find (List *ls, const char *name_to_find)
{
  List *cur = ls;
  while (cur)
  {
    if (strcmp(cur -> name, name_to_find) == 0)
    {
      return cur;
    }
    cur = cur -> next;
  }
  return nullptr;
}


void add(List *&ls, const char *new_name, unsigned int new_phone)
{
  if (!ls) //if ls is empty
  {
    ls = new List;
    ls -> name = new char[strlen(new_name)];
    strcpy(ls -> name, new_name);
    ls -> phone_number = new_phone;
    ls -> next = nullptr;
    return;
  }
    
  List * cur = new List{};
  cur = ls;
  while (cur -> next) //checking everything in the middle;
  {
    if (strcmp(cur-> name, new_name) == 0)
    {
      cur -> phone_number = new_phone;
      return;
    }
    cur = cur -> next;
  }
    
  if (cur && strcmp(cur -> name, new_name) == 0) //checking the last one
  {
    cur -> phone_number = new_phone;
    return;
  }
  //adding a new entry
  cur -> next = new List{};
  cur = cur -> next;
  cur -> name = new char[strlen(new_name)];
  strcpy(cur -> name, new_name);
  cur -> phone_number = new_phone;
  cur -> next = nullptr;
}


bool remove(List *&ls, const char * name_to_delete)
{
  List *cur = ls;
  if (strcmp(cur -> name, name_to_delete) == 0) //Only the head can get there
  {
    ls = cur -> next;
    delete[] cur -> name;
    delete cur;
    return true;
  }
    
  while (cur)
  {
    if (cur -> next && strcmp(cur -> next -> name, name_to_delete) == 0) //for something in the middle or at the end
    {
      List *will_be_deleted = cur -> next;
      cur -> next = cur -> next -> next;
      delete[] will_be_deleted -> name;
      delete will_be_deleted;
      return true;
    }
    cur = cur -> next;
  }
  //if we got here, means we didn't find anything
  return false;
}

void printToFile (map <string,int> &m, string fl)
{
    std::ofstream fout;
    fout.open(fl);
    for(auto const &e: m) fout << e . first << " " << e.second << std::endl;
}

void printList(List * ls)
{
  List * cur = ls;
  while (cur)
  {
    printf("\nName: %s\nPhone: %d\n", cur -> name, cur -> phone_number);
    cur = cur -> next;
  }
}

List * wildcardFind (List * given_list, const char * name_to_find)
{
  List *cur = given_list;
  List * buff_list = nullptr;
  while (cur)
  {
    if (checkMask(name_to_find, cur -> name))
    {
      add(buff_list, cur -> name, cur -> phone_number);
    }
    cur = cur -> next;
  }
  return buff_list;
}*/