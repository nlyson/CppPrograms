/******************************************************************************

Nathan Lyson
WhichAreIn.cpp

Given two arrays of strings a1 and a2 return a sorted array r in lexicographical order of the strings of a1 which are substrings of strings of a2.

Example 1:
a1 = ["arp", "live", "strong"]

a2 = ["lively", "alive", "harp", "sharp", "armstrong"]

returns ["arp", "live", "strong"]

Example 2:
a1 = ["tarp", "mice", "bull"]

a2 = ["lively", "alive", "harp", "sharp", "armstrong"]

returns []

Notes:
Arrays are written in "general" notation. See "Your Test Cases" for examples in your language.
In Shell bash a1 and a2 are strings. The return is a string where words are separated by commas.
Beware: r must be without duplicates.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class WhichAreIn
{

  public:
    static std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2)
    {
        std::vector<std::string> result{};
        
        
        // Outer loop - substrings to check
        for(auto i=0; i<array1.size(); i++)
        {
            // Try to find the substring in array2 
            // If I find it, break out of the loop so I don't add it to result more than once
            for(auto j=0; j<array2.size(); j++)
            {
                if(array2[j].find(array1[i]) != std::string::npos)
                {
                    result.push_back(array1[i]);
                    break;
                    
                }
            }
        }
        
        // Sort and return result
        std::sort(result.begin(), result.end());
        
        return result;
    }


};

void printVector(vector<string> v)
{
    for(string n : v)
        cout << n << " ";
    
    cout << endl;
}

int main()
{
    // Test cases
    vector<string> test1 = {"arp", "live", "strong"};
    vector<string> test2 = {"lively", "alive", "harp", "sharp", "armstrong"};
    vector<string> test3 = {"tarp", "mice", "bull"};
    vector<string> test4 = {"lively", "alive", "harp", "sharp", "armstrong"};
    printVector( WhichAreIn::inArray(test1, test2) );
    printVector( WhichAreIn::inArray(test3, test4) );

    return 0;
}
