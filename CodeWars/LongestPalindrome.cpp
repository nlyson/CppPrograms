/******************************************************************************

    Nathan Lyson
    LongestPalindrome.cpp
    
Longest Palindrome
Find the length of the longest substring in the given string s that is the same in reverse.

As an example, if the input was “I like racecars that go fast”, the substring (racecar) length would be 7.

If the length of the input string is 0, the return value must be 0.

Example:
"a" -> 1 
"aab" -> 2  
"abcde" -> 1
"zzbaabcd" -> 4
"" -> 0

*******************************************************************************/

#include <iostream>

using namespace std;

int longest_palindrome(const std::string &s)
{
    
    int maxLength = 1;
    int length = s.length();
    
    // Easy case - return 0 if string is empty
    if(length < 1)
        return 0;
    
    for(int i=0; i<length; i++)
    {
        // Odd pali - lets build an odd pali centered at spot i and see how  
        // big we can make it.
        int paliLen = 1;
        int left = i-1;
        int right = i+1;
        
        while(left >= 0 && right < length && s[left] == s[right])
        {
            --left;
            ++right;
            paliLen += 2;
        }
        
        if(paliLen > maxLength)
            maxLength = paliLen;
            
        
        // Lets build an even pali centered at spots i and i + 1 and see 
        // how big we can make it.
        paliLen = 0;
        left = i;
        right = i+1;
        while(left >= 0 && right < length && s[left] == s[right])   
        {
            --left;
            ++right;
            paliLen += 2;
        }
        
        if(paliLen > maxLength)
            maxLength = paliLen; 
        
    }
    
     
    return maxLength;
}

int main()
{
    // Test cases
    string s = "i am a racecar adda";
    cout<< longest_palindrome(s) << endl;
    cout << longest_palindrome("baablkj12345432133d");
   

    return 0;
}
