
/******************************************************************************
CamelCase.cpp
Nathan Lyson
Complete the method/function so that it converts dash/underscore delimited words into camel casing. 
The first word within the output should be capitalized only if the original word was capitalized (known as Upper Camel Case, also often referred to as Pascal case).

Examples
"the-stealth-warrior" gets converted to "theStealthWarrior"
"The_Stealth_Warrior" gets converted to "TheStealthWarrior"
*******************************************************************************/

#include <string>


std::string to_camel_case(std::string text) 
{  
   auto i=0;
   while(i++<text.length())
   {
      // Look for non-alpha characters.  Remove them and make following character uppercase.  (If it's there.)
      if(!isalpha(text[i]))
      {
         if(i+1 < text.length())
         {
            text.replace(i+1, 1, 1, toupper(text[i+1]));
            text.erase(i--, 1);
         }
      }
   }
   return text;
}
