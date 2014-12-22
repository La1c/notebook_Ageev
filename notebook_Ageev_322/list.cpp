#include "list.h"
#include <ctype.h>
#include <string.h>

//DB entry -- List is defined in the .h file


bool CheckMask(const char * str_with_mask, const char * str_to_check)
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

List * Find (List *ls, const char *name_to_find)
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


void Add(List *&ls, const char *new_name, unsigned int new_phone)
{
    if(!ls) //if ls is empty
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
    while(cur -> next) //checking everything in the middle;
    {
     
            if(strcmp(cur-> name, new_name) == 0)
           {
               cur -> phone_number = new_phone;
               return;
           }
        
            cur = cur -> next;
    }
    
    if(cur && strcmp(cur -> name, new_name) == 0) //checking the last one
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


bool Remove(List *&ls, const char * name_to_delete)
{
    List *cur = ls;
    
    if(strcmp(cur -> name, name_to_delete) == 0) //Only the head can get there
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

void PrintToFile (List *&ls, FILE * fl)
{
    if(ls -> name)
    {
        List * cur = ls;
        while (cur)
        {
            fprintf(fl, "%s %d\n", cur -> name, cur -> phone_number);
            cur = cur -> next;
        }
    }
}

void PrintList(List * ls)
{
    List * cur = ls;
    while (cur)
    {
        printf("\nName: %s\nPhone: %d\n", cur -> name, cur -> phone_number);
        cur = cur -> next;
    }
}

List * AddvancedFind (List * given_list, const char * name_to_find)
{
    List *cur = given_list;
    List * buff_list = nullptr;
    while (cur)
    {
        if (CheckMask(name_to_find, cur -> name))
        {
            Add(buff_list, cur -> name, cur -> phone_number);
        }
        cur = cur -> next;
    }
    return buff_list;
}