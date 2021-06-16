/******************************************************************************

Nathan Lyson
DuplicateEncoder.cpp

The goal of this exercise is to convert a string to a new string where each character in the new string is "(" if that 
character appears only once in the original string, or ")" if that character appears more than once in the original string. 
Ignore capitalization when determining if a character is a duplicate.

Examples
"din"      =>  "((("
"recede"   =>  "()()()"
"Success"  =>  ")())())"
"(( @"     =>  "))((" 

*******************************************************************************/

#include <iostream>
#include <string>
#include <map>
#include<bits/stdc++.h>



using namespace std;


string duplicate_encoder(const std::string& word){
    
    // Make a copy of word and make it lowercase
    string w = word;
    transform(w.begin(), w.end(), w.begin(), ::tolower);
    
    
    // Create a mapping of all characters in the string along with the number of occurences
    map<char, int> letters;
    
    for(char c : w)
        letters[c]++;
    
    
    // Print '(' or ')' based on number of occurences
    for(int i=0; i<w.size(); i++)
        if(letters[w[i]] == 1)
            w[i] = '(';
        else
            w[i] = ')';
    

    return w;
}

int main()
{
    // Test cases
    cout << duplicate_encoder("din") << endl;
    cout << duplicate_encoder("recede") << endl;
    cout << duplicate_encoder("Success") << endl;
    
    
    return 0;
}
