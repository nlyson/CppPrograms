/******************************************************************************
ReverseWords.cpp
Complete the function that accepts a string parameter, and reverses each word in the string. All spaces in the string should be retained.

Examples
"This is an example!" ==> "sihT si na !elpmaxe"
"double  spaces"      ==> "elbuod  secaps"
*******************************************************************************/

std::string reverse_words(std::string str)
{
   // Create a stringstream to store the completed reversed string
   std::stringstream reverseStr;
  
   for(std::string::iterator it=str.begin(); it < str.end(); ++it)
   {
      // Add characters to the beginning of a temp string until you get to a space
      std::string reverseWord;
      while(it < str.end() && *it != ' ')
      {
         reverseWord.insert(reverseWord.begin(), *it);
         it++;
      }
     
      // We found a space.  Put this word in our stringstream and move on to the next word
      reverseStr << reverseWord << " ";
   }
   
   // Only return number of characters in original string to avoid extra spaces at the end
   return reverseStr.str().substr(0, str.size());
}
