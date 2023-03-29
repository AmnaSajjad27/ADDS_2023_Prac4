#include <string>
#include <vector>
#include <iostream> 

#include "Finder.h"

// optimised code 

vector<int> Finder::findSubstrings(string s1, string s2) 
{
    // the size is determined here 
    // Initalised to -1 so we do not need the else statement at the end for the for loop when the prefix is not found

    vector <int> result(s2.size(), -1);
    // this string holds the current substring being searched for 
    string current_Substring;
    
    size_t found = 0;
    
    // same for loop as before to iterate 
    for (size_t i = 1; i <= s2.size(); i++) 
    {
        // starting position for each subsequent search is set to the index of the previous match (result[i-2]+1)
        // this helps by elimintating instances where a shorter prefix has not been found  

        current_Substring = s2.current_Substring(0, i);

        // find the substring 
        found = (i == 1) ? s1.find(current_Substring) : s1.find(current_Substring, result[i-2]+1);

        // if statemnt untill the end of the string 
        // if not found, return the last one found outside the loop 
        if (found != string::npos)
        {
            result[i-1] = found;
        }
    }
    return result;
}
