#include <string>


std::string to_camel_case(std::string text) {
  
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
