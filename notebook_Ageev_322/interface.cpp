#include "interface.h"
#include <string>
#include <cstdio>
#include <memory>

using std::string;
using std::map;
using std::cout;
using std::cin;
using std::endl;

//checks if there are numbers in the name given
bool checkData(string name)
{
    for(auto &e : name)
  {
    if (isdigit(e)) return false;
  }
  return true;
}


//just a menu
void interface(DB & myDB)
{
  printf("Hello!\n");
  int option = 1;
  while (option)
  {
    cout << "Choose your action, please:\n\n1)Add\n2)Find\n3)Delete\n0)Exit\n\n";
    cin >> option;
    while (option > 3 || option < 0)
    {
      cout << "\nTry again, please\n";
      cin >> option;
    }
        
    switch (option)
    {
      case 1:
      {
        while (1)
        {
                    
            printf("\nEnter a name please, or go back by entering 0:\n");
          
            string given_name;
            unsigned int phone;
            cin >> given_name;
            
            if (given_name.length() == 1 && given_name[0] == '0') break;
            while (!checkData(given_name))
            {
                cout << endl <<"Try again, please" << endl;
                cin >> given_name;
            }
                
            printf("\nEnter a phone number:\n");
            cin >> phone;
                    
            myDB.addToDB(given_name, phone);
            cout << endl << "Done!" << endl;
        }
     }
     break;
     
     case 2:
     {
       while (1)
       {
           cout << endl << "Enter a name to find, please, or go back by entering 0:" << endl;
           string given_name;
           cin >> given_name;
           
           if (given_name.length() == 1 && given_name[0] == '0') break;
           while (!checkData(given_name))
           {
               cout << endl << "Try again, please" << endl;
               cin >> given_name;
           }
                
           auto was_found = myDB.findInDB(given_name);
           if (was_found.size())
           {
              for (auto &e: was_found) cout << e.first << " " << e.second << std::endl;
           }
           else
           {
             cout << "Sorry, nothing was found!" << endl;
           }
       }
     }
      break;
            
      case 3:
      {
        while (1)
        {
            cout << endl << "Enter a name to remove, please, or go back by entering 0:" << endl;
            string given_name;
            cin >> given_name;
            
            if (given_name.length() == 1 && given_name[0] == '0') break;
            while (!checkData(given_name))
            {
                cout << endl <<"Try again, please" << endl;
                cin >> given_name;
            }
            
            if (myDB.deleteFromDB(given_name))
            {
                cout << "Entry was removed correctly!" << endl;
            }
            else
            {
                cout << "Nothing was found to remove!" << endl;
            }
        }
      }
      break;
                
      case 0:
      {
        cout << "Bye!";
        return;
      }
      break;
      
      default:
        break;
    }
  }
}