#include "tests.h"
#include "controller.h"
#include "gtest.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <utility>

using std::string;
using std::ifstream;
using std::map;
using std::find;
using std::make_pair;
using myPair = std::pair<string, unsigned int>;

//Adding, finding, and changing
TEST(AddAndFind, AddSomething)
{
    DB myDB;
    myDB.addToDB("Some Name", 100);
    auto was_found = myDB.findInDB("Some Name");
    myPair p = make_pair("Some Name", 100);
    auto found = find(was_found.begin(), was_found.end(), p);
    EXPECT_TRUE((*found).first == "Some Name" && (*found).second == 100);

    myDB.addToDB("Another Name", 200);
    was_found = myDB.findInDB("Another Name");
    p = make_pair("Another Name", 200);
    found = find(was_found.begin(), was_found.end(), p);
    
    EXPECT_TRUE((*found).first == "Another Name" && (*found).second == 200);
    
    myDB.addToDB("Some Name", 300);
    was_found = myDB.findInDB("Some Name");
    p = make_pair("Some Name", 300);
    found = find(was_found.begin(), was_found.end(), p);
    
    EXPECT_TRUE((*found).first == "Some Name" && (*found).second == 300);
}

//Let's try to add 100 elements and find each of them
TEST(AddAndFind, Add100)
{
    DB myDB;
    ifstream fin("test_names.txt");
  if (fin)
  {
    string name_from_file;
    int i = 100;
        
    while (fin >> name_from_file)
    {
      myDB.addToDB(name_from_file, i);
      ++i;
    }
  }
    
    fin.close();
    fin.open("test_names.txt");
  
    if (fin)
  {
    string name_from_file;
    int i = 100;
        
    while (fin >> name_from_file)
    {
      auto was_found = myDB.findInDB(name_from_file);
      myPair p = make_pair(name_from_file, i);
      auto found = find(was_found.begin(), was_found.end(), p);
      EXPECT_TRUE((*found).first == name_from_file && (*found).second == i);
      ++i;
    }
  }
}

//Let's try find something in empty list
TEST(Find, FindEmpty)
{
  DB myDB;
    EXPECT_FALSE(myDB.findInDB("Name").size());
}

//Let's try to find something not in the list
TEST(Find, DoesntExist)
{
  DB myDB;
  
  myDB.addToDB("Some Name", 100);
  myDB.addToDB("Another Name", 200);
  myDB.addToDB("Third Name", 300);
    
 EXPECT_FALSE(myDB.findInDB("Super Man").size());
}

//Adding than removing 100 elements
TEST(Remove, BigTest)
{
    DB myDB;
    ifstream fin("test_names.txt");
    string name_from_file;
    
  if (fin)
  {
    
    int i = 100;
        
    while (fin >> name_from_file)
    {
      myDB.addToDB(name_from_file, i);
      ++i;
    }
  }
    
    fin.close();
    fin.open("test_names.txt");
    
  if (fin)
  {
    while (fin >> name_from_file)
    {
        myDB.deleteFromDB(name_from_file);
      //delete successfuly
      EXPECT_FALSE(myDB.findInDB(name_from_file).size());
    }
  }
  //everything should be deleted
    EXPECT_FALSE(myDB.count());
}

int run_all_tests(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}