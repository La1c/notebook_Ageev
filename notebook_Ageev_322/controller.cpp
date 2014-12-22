#include <cstdio>
#include <cstdlib>
#include "interface.h"
#include "controller.h"
#include "list_tests.h"

FILE * data = nullptr;
List * myls = nullptr;

//Saving to file
void DBDown()
{
    data = fopen("data.txt", "w");
    if(data)
    {
        PrintToFile(myls, data);
    }
    fclose(data);
}

//Loading from file
void DBUp()
{
    data = fopen("data.txt", "r");
    if(data)
    {
        char * name_from_file = new char;
        unsigned int number_from_file;
        
        while(fscanf(data, "%s%d\n", name_from_file, &number_from_file) == 2)
        {
            Add(myls, name_from_file, number_from_file);
        }
    }
    fclose(data);
}

List * FindInDB(const char *seeked_name)
{
   return AddvancedFind(myls, seeked_name);
}

void AddToDB(const char *new_name, unsigned int new_number)
{
    Add(myls, new_name, new_number);
}


bool DeleteFromDB(const char *name_to_delete)
{
   return Remove(myls, name_to_delete);
}

void Print(List * ls)
{
    PrintList(ls);
}

int main(int argc, char ** argv)
{
    run_all_tests(argc, argv);
    DBUp();
    Interface();
    return 0;
}
