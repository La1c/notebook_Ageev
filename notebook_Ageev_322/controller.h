#include <utility>
#include <memory>
#include <map>
#include <string>
#include <fstream>
#include <iostream>

using std::map;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::shared_ptr;

#pragma once

class DB
{
public:
    
    DB()
    {
        //reading data from file
        std::ifstream fin("data.txt");
        if (fin)
        {
            string name_from_file;
            unsigned int number_from_file;
            
            while (fin >> name_from_file >> number_from_file)
            {
                addToDB(name_from_file, number_from_file);
            }
        }
        fin.close();
    }
    
    ~DB()
    {
        //filling file with data left
        std::ofstream fout("data.txt");
        if (fout)
        {
            for(auto const &e: mData) fout << e . first << " " << e.second << std::endl;
        }
        
        fout.close();
    }
    
    void addToDB(string new_name, unsigned int new_number)
    {
        mData[new_name] = new_number;
    }
    
    bool deleteFromDB(string name_to_delete)
    {
        return  (mData.erase(name_to_delete) == 1);
    }
    
    shared_ptr<map<string, unsigned int>> findInDB(string seeked_name) //wildcard search
    {
        map<string, unsigned int> mapToReturn;
        for(auto &e: mData)
        {
            if (checkMask(seeked_name, e.first)) //checking if current name fits the mask
            {
                mapToReturn[e.first] = e.second;
            }
        }
        return std::make_shared<map<string, unsigned int>>(mapToReturn);
    }

    void print()
    {
        for(auto &e: mData) cout << e.first << " " << e.second;
    }
    
    size_t count()
    {
        return mData.size();
    }
    
private:
    map<string, unsigned int> mData;
    
    //checking if current name fits the mask
    bool checkMask(const string str_with_mask, const string str_to_check)
    {
        if (str_with_mask.length() == str_to_check.length())
        {
            size_t len = str_with_mask.length();
            for(size_t i = 0; i < len; ++i)
            {
                if (str_with_mask[i] != '?' && str_with_mask[i] != str_to_check[i])
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};
