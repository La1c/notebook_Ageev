#include "list_tests.h"
#include "list.h"
#include "gtest.h"
#include <string.h>

//Adding, finding, and changing
TEST(AddAndFind, AddSomething)
{
    List * myls = nullptr;
    Add(myls, "Some Name", 100);
    List * was_found = Find(myls, "Some Name");
    EXPECT_TRUE(was_found);
    EXPECT_TRUE((strcmp(was_found -> name, "Some Name") == 0) && was_found -> phone_number == 100);
    
    Add(myls, "Another Name", 200);
    was_found = Find(myls, "Another Name");
    EXPECT_TRUE(was_found);
    EXPECT_TRUE((strcmp(was_found -> name, "Another Name") == 0) && was_found -> phone_number == 200);
    
    Add(myls, "Some Name", 300);
    was_found = Find(myls, "Some Name");
    EXPECT_TRUE(was_found);
    EXPECT_TRUE((strcmp(was_found -> name, "Some Name") == 0) && was_found -> phone_number == 300);
}

//Let's try to add 100 elements and find each of them
TEST(AddAndFind, Add100)
{
    List * myls = nullptr;
    List * was_found = nullptr;
    
    FILE * data = fopen("test_names.txt", "r");
    if(data)
    {
        char * name_from_file = new char;
        int i = 100;
        
        while(fscanf(data, "%s\n", name_from_file) == 1)
        {
            Add(myls, name_from_file, i);
             ++i;
        }
    }
    fclose(data);
    data = fopen("test_names.txt", "r");
    if(data)
    {
        char * name_from_file = new char;
        int i = 100;
        
        while(fscanf(data, "%s\n", name_from_file) == 1)
        {
            was_found = Find(myls, name_from_file);
            EXPECT_TRUE(was_found);
            EXPECT_TRUE((strcmp(was_found -> name, name_from_file) == 0) && was_found -> phone_number == i);
            ++i;
        }
    }
    fclose(data);
}

//Let's try find something in empty list
TEST(Find, FindEmpty)
{
    List *myls = nullptr;
    EXPECT_TRUE(!Find(myls, "Name"));
}

//Let's try to find something not in the list
TEST(Find, DoesntExist)
{
    List * myls = nullptr;
  
    Add(myls, "Some Name", 100);
    Add(myls, "Another Name", 200);
    Add(myls, "Third Name", 300);
    
    EXPECT_TRUE(!Find(myls, "Super Man"));
}

//Removing head and checking a new one
TEST(Remove, Head)
{
    List * myls = nullptr;
    
    Add(myls, "Some Name", 100);
    Add(myls, "Another Name", 200);
    Add(myls, "Third Name", 300);
    
    Remove(myls, "Some Name");
    EXPECT_TRUE(!Find(myls, "Some Name"));
    EXPECT_TRUE(strcmp(myls -> name, "Another Name") == 0);
}
//Removing the seond element
TEST(Remove, Middle)
{
    List * myls = nullptr;
    
    Add(myls, "Some Name", 100);
    Add(myls, "Another Name", 200);
    Add(myls, "Third Name", 300);
    
    Remove(myls, "Another Name");
    EXPECT_TRUE(!Find(myls, "Another Name"));
    EXPECT_TRUE(strcmp(myls -> next -> name, "Third Name") == 0);
}
//Removing the last element
TEST(Remove, Last)
{
    List * myls = nullptr;
    
    Add(myls, "Some Name", 100);
    Add(myls, "Another Name", 200);
    Add(myls, "Third Name", 300);
    
    Remove(myls, "Third Name");
    EXPECT_TRUE(!Find(myls, "Third Name"));
    EXPECT_TRUE(!myls -> next -> next);
}

//Adding than removing 100 elements
TEST(Remove, BigTest)
{
    List * myls = nullptr;
    
    FILE * data = fopen("test_names.txt", "r");
    if(data)
    {
        char * name_from_file = new char;
        int i = 100;
        
        while(fscanf(data, "%s\n", name_from_file) == 1)
        {
            Add(myls, name_from_file, i);
            ++i;
        }
    }
    fclose(data);
    data = fopen("test_names.txt", "r");
    if(data)
    {
        char * name_from_file = new char;
        
        while(fscanf(data, "%s\n", name_from_file) == 1)
        {
            Remove(myls, name_from_file);
            //delete successful
            EXPECT_TRUE(!Find(myls, name_from_file));
        }
    }
    fclose(data);
    //everything should be deleted
    EXPECT_TRUE(!myls);
}

int run_all_tests(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}