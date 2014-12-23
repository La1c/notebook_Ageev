#include "list_tests.h"
#include "list.h"
#include "gtest.h"
#include <string.h>

//Adding, finding, and changing
TEST(AddAndFind, AddSomething)
{
    List * myls = nullptr;
    add(myls, "Some Name", 100);
    List * was_found = find(myls, "Some Name");
    EXPECT_TRUE(was_found);
    EXPECT_TRUE((strcmp(was_found -> name, "Some Name") == 0) && was_found -> phone_number == 100);
    
    add(myls, "Another Name", 200);
    was_found = find(myls, "Another Name");
    EXPECT_TRUE(was_found);
    EXPECT_TRUE((strcmp(was_found -> name, "Another Name") == 0) && was_found -> phone_number == 200);
    
    add(myls, "Some Name", 300);
    was_found = find(myls, "Some Name");
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
            add(myls, name_from_file, i);
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
            was_found = find(myls, name_from_file);
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
    EXPECT_FALSE(find(myls, "Name"));
}

//Let's try to find something not in the list
TEST(Find, DoesntExist)
{
    List * myls = nullptr;
  
    add(myls, "Some Name", 100);
    add(myls, "Another Name", 200);
    add(myls, "Third Name", 300);
    
    EXPECT_FALSE(find(myls, "Super Man"));
}

//Removing head and checking a new one
TEST(Remove, Head)
{
    List * myls = nullptr;
    
    add(myls, "Some Name", 100);
    add(myls, "Another Name", 200);
    add(myls, "Third Name", 300);
    
    remove(myls, "Some Name");
    EXPECT_FALSE(find(myls, "Some Name"));
    EXPECT_TRUE(strcmp(myls -> name, "Another Name") == 0);
}
//Removing the seond element
TEST(Remove, Middle)
{
    List * myls = nullptr;
    
    add(myls, "Some Name", 100);
    add(myls, "Another Name", 200);
    add(myls, "Third Name", 300);
    
    remove(myls, "Another Name");
    EXPECT_FALSE(find(myls, "Another Name"));
    EXPECT_TRUE(strcmp(myls -> next -> name, "Third Name") == 0);
}
//Removing the last element
TEST(Remove, Last)
{
    List * myls = nullptr;
    
    add(myls, "Some Name", 100);
    add(myls, "Another Name", 200);
    add(myls, "Third Name", 300);
    
    remove(myls, "Third Name");
    EXPECT_FALSE(find(myls, "Third Name"));
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
            add(myls, name_from_file, i);
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
            remove(myls, name_from_file);
            //delete successful
            EXPECT_FALSE(find(myls, name_from_file));
        }
    }
    fclose(data);
    //everything should be deleted
    EXPECT_FALSE(myls);
}

int run_all_tests(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}