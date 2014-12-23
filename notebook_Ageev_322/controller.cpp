#include <cstdio>
#include <cstdlib>
#include "interface.h"
#include "controller.h"
#include "list_tests.h"

FILE * data = nullptr;
List * myls = nullptr;

//Saving to file
void dbDown()
{
    data = fopen("data.txt", "w");
    if(data)
    {
        printToFile(myls, data);
    }
    fclose(data);
    List * cur_to_be_deleted = nullptr;
    
    while (myls)
    {
        cur_to_be_deleted = myls;
        myls = myls -> next;
        delete[] cur_to_be_deleted -> name;
        delete cur_to_be_deleted;
    }
    
}

//Loading from file
void dbUp()
{
    data = fopen("data.txt", "r");
    if(data)
    {
        char * name_from_file = new char;
        unsigned int number_from_file;
        
        while(fscanf(data, "%s%d\n", name_from_file, &number_from_file) == 2)
        {
            add(myls, name_from_file, number_from_file);
        }
    }
    fclose(data);
}

List * findInDB(const char *seeked_name)
{
   return wildcardFind(myls, seeked_name);
}

void addToDB(const char *new_name, unsigned int new_number)
{
    add(myls, new_name, new_number);
}


bool deleteFromDB(const char *name_to_delete)
{
   return remove(myls, name_to_delete);
}

void print(List * ls)
{
    printList(ls);
}

int main(int argc, char ** argv)
{
    run_all_tests(argc, argv);
    dbUp();
    interface();
    return 0;
}
