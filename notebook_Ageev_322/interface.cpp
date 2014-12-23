#include "interface.h"
#include <cstdlib>
#include <cstdio>
#include <ctype.h>
#include <stdio.h>

bool CheckData(const char *name)
{
    while(*name++)
    {
        if(isdigit(*name)) return false;
    }
    return true;
}

void interface(DB & myDB)
{
    printf("Hello!\n");
    int option = 1;
    while(option)
    {
        printf("Choose your action, please:\n\n1)Add\n2)Find\n3)Delete\n0)Exit\n\n");
        scanf("%d", &option);
        while(option > 3 || option < 0)
        {
            printf("\nTry again, please\n");
            scanf("%d", &option);
        }
        
        switch (option)
        {
            case 1:
            {
                while (1)
                {
                    
                    printf("\nEnter a name please, or go back by entering 0:\n");
                    char * given_name = new char;
                    char * phone_buff = new char;
                
                    scanf("%s",given_name);
                    if(isdigit(*given_name) && atoi(given_name) == 0) break;
                    while (!CheckData(given_name))
                    {
                        printf("\nTry again, please\n");
                        scanf("%s",given_name);
                    }
                
                    printf("\nEnter a phone number:\n");
                    scanf("%s", phone_buff);
                    
                    while (!isdigit(*phone_buff))
                    {
                        printf("Phone isn't correct!Try again!\n");
                        scanf("%s", phone_buff);
                    }
                    
                    addToDB(myDB, given_name, atoi(phone_buff));
                    printf("\nDone!\n");
                }
            }
                break;
            case 2:
            {
                while (1)
                {
                    printf("\nEnter a name, please, or go back by entering 0:\n");
                        char * given_name = new char;
                        scanf("%s",given_name);
                        if(isdigit(*given_name) && atoi(given_name) == 0) break;
                        while (!CheckData(given_name))
                        {
                            printf("\nTry again, please\n");
                            scanf("%s",given_name);
                        }
                
                    List * was_found = findInDB(myDB, given_name);
                    if (was_found)
                    {
                        print(was_found);
                    }
                    else
                    {
                        printf("Sorry, nothing was found!\n");
                    }
                }

            }
                break;
            
            case 3:
            {
                while (1)
                {
                    printf("\nEnter a name to remove, please, or go back by entering 0:\n");
                    char * given_name = new char;
                    scanf("%s",given_name);
                    if(isdigit(*given_name) && atoi(given_name) == 0) break;
                    while (!CheckData(given_name))
                    {
                        printf("\nTry again, please\n");
                        scanf("%s",given_name);
                    }
                    
                    bool was_deleted = deleteFromDB(myDB, given_name);
                    if (was_deleted)
                    {
                        printf("Entry was removed correctly!\n");
                    }
                    else
                    {
                        printf("Nothing was found to remove!\n");
                    }
                }

            }
                break;
                
            case 0:
                printf("Bye!");
                dbDown(myDB);
                return;
                break;
            default:
                break;
        }
        
    }
}