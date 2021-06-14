/******************************************************************************

CountChars.cpp

Nathan Lyson

The main idea is to count all the occurring characters in a string. If you have a string like aba, then the result should be {'a': 2, 'b': 1}.

What if the string is empty? Then the result should be empty object literal, {}.

*******************************************************************************/

#include <iostream>
#include <map>
#include <string>



std::map<char, unsigned> count(const std::string& string) {
  
    std::map<char, unsigned> result;
    
    int len = string.length();
    
    // Iterate through string
    // If char is already in map, increase value by 1 
    // Otherwise, create a new mapping with value of 1  
    for(int i=0; i<len; i++)
    {
        if(result.count(string[i]) > 0)
            result[string[i]] = result[string[i]] + 1;
        else
            result[string[i]] = 1;
    }
   
    
  
  
    return result;
}

void printMap(std::map<char, unsigned> m)
{
    for(auto const &pair : m)
        std::cout << pair.first << " " << pair.second << std::endl;
        
    std::cout << std::endl;
}

int main()
{
    // Test cases
    printMap( count("Hello") );
    printMap( count("World") );
    printMap( count("I am a test case!") );
 
    
    return 0;
}
