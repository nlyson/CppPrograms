/******************************************************************************

Nathan Lyson
MovingShift.cpp

The action of a Caesar cipher is to replace each plaintext letter (plaintext letters are from 'a' to 'z' or from 'A' to 'Z') with a different one a fixed number of places up or down the alphabet.

This program performs a variation of the Caesar shift. The shift increases by 1 for each character (on each iteration).

If the shift is initially 1, the first character of the message to be encoded will be shifted by 1, the second character will be shifted by 2, etc...

Coding: Parameters and return of function "movingShift"
param s: a string to be coded

param shift: an integer giving the initial shift

The function "movingShift" first codes the entire string and then returns an array of strings containing the coded string in 5 parts (five parts because, to avoid more risks, the coded message will be given to five runners, one piece for each runner).

If possible the message will be equally divided by message length between the five runners. If this is not possible, parts 1 to 5 will have subsequently non-increasing lengths, such that parts 1 to 4 are at least as long as when evenly divided, but at most 1 longer. If the last part is the empty string this empty string must be shown in the resulting array.

For example, if the coded message has a length of 17 the five parts will have lengths of 4, 4, 4, 4, 1. The parts 1, 2, 3, 4 are evenly split and the last part of length 1 is shorter. If the length is 16 the parts will be of lengths 4, 4, 4, 4, 0. Parts 1, 2, 3, 4 are evenly split and the fifth runner will stay at home since his part is the empty string. If the length is 11, equal parts would be of length 2.2, hence parts will be of lengths 3, 3, 3, 2, 0.

You will also implement a "demovingShift" function with two parameters

Decoding: parameters and return of function "demovingShift"
an array of strings: s (possibly resulting from "movingShift", with 5 strings)

an int shift

"demovingShift" returns a string.

Example:
u = "I should have known that you would have a perfect answer for me!!!"

movingShift(u, 1) returns :

v = ["J vltasl rlhr ", "zdfog odxr ypw", " atasl rlhr p ", "gwkzzyq zntyhv", " lvz wp!!!"]

(quotes added in order to see the strings and the spaces, your program won't write these quotes, see Example Test Cases)

and demovingShift(v, 1) returns u. #Ref:

Caesar Cipher : http://en.wikipedia.org/wiki/Caesar_cipher

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;


class CaesarCipher
{
  public:
  
    // This function can be used for encrypting and decrypting
    // shiftForward(c, shift) will encrypt 
    // shiftForward(c, 26 - shift) will decypt 
    static char shiftForward(char c, int shift)
    {
        char replaceChar = c;
        if( c >= 'A' && c <= 'Z' )
            replaceChar = (replaceChar - 'A' + shift) % 26 + 'A';
        else if( c >= 'a' && c <= 'z' )
            replaceChar = (replaceChar - 'a' + shift) % 26 + 'a';
            
        return replaceChar;
    }
    
  
    static std::vector<std::string> movingShift(const std::string &s, int shift)
    {
        // Initialize values assuming string length is divisible by 5
        int length = s.length();
        int partLength = length / 5;
        int leftOvers = 0;
        
        // If string length is not divisible by 5, replace values per instructions
        // 4 even parts - then 1 part with leftovers
        if(length % 5 != 0)
        {
            partLength = length / 5 + 1;
            leftOvers = length % 4;
        }
        
        // Perform shift
        string result = "";
        for(int i=0; i<length; i++)
        {
            result += shiftForward(s[i], shift);
            shift++;
                
        }
        

        
        return { result.substr(0, partLength), result.substr(partLength, partLength),
                 result.substr(partLength*2, partLength), result.substr(partLength*3, partLength),
                 result.substr(partLength*4, string::npos ) };
        
        
        
    }
    static std::string demovingShift(std::vector<std::string> &s, int shift)
    {
        
        string combined = "";
        
        for(string str : s)
            combined = combined + str;
            
        int length = combined.length();
            

        // Perform shift
        string result = "";
        for(int i=0; i<length; i++)
        {
            shift = shift % 26;
            result += shiftForward(combined[i], 26 - shift);
            shift++;
                
        }
        
        return result;
    }
};




void printVector(vector<string> v)
{
    for(string s : v)
        cout << s << endl;
    
    cout << endl;
}

int main()
{
    // Test cases
    string test1 = "I should have known that you would have a perfect answer for me!!!";
    
    printVector( CaesarCipher::movingShift(test1, 1) );
    
    vector<string> result1 = CaesarCipher::movingShift(test1, 1);
    
    cout << CaesarCipher::demovingShift( result1 , 1);
    

    return 0;
}
