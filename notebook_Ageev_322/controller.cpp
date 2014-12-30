#include <cstdio>
#include <cstdlib>
#include "interface.h"
#include "controller.h"
#include "list_tests.h"

FILE * data = nullptr;

//Saving to file
void dbDown(DB &mydb)
{
  data = fopen("data.txt", "w");
  if(data)
  {
    printToFile(mydb.ls, data);
  }
  
  fclose(data);
  List * cur_to_be_deleted = nullptr;
  List * myls = mydb.ls;
    
  while (myls)
  {
    cur_to_be_deleted = myls;
    myls = myls -> next;
    delete[] cur_to_be_deleted -> name;
    delete cur_to_be_deleted;
  }
}

//Loading from file
void dbUp(DB & mydb)
{
  data = fopen("data.txt", "r");
  if(data)
  {
    char * name_from_file = new char;
    unsigned int number_from_file;
        
    while (fscanf(data, "%s%d\n", name_from_file, &number_from_file) == 2)
    {
        add(mydb.ls, name_from_file, number_from_file);
    }
  }
  fclose(data);
}

List * findInDB(DB &mydb, const char *seeked_name)
{
  return wildcardFind(mydb.ls, seeked_name);
}

void addToDB(DB & mydb, const char *new_name, unsigned int new_number)
{
  add(mydb.ls, new_name, new_number);
}


bool deleteFromDB(DB & mydb, const char *name_to_delete)
{
  return remove(mydb.ls, name_to_delete);
}

void print(List * ls)
{
  printList(ls);
}

int main(int argc, char ** argv)
{
  DB * myDB = new DB{nullptr};
  run_all_tests(argc, argv);
  dbUp(*myDB);
  interface(*myDB);
  return 0;
}
