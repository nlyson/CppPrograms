/******************************************************************************
CountChars.cpp
Nathan Lyson

The rgb function is incomplete. Complete it so that passing in RGB decimal values will result in a hexadecimal representation being returned. 
Valid decimal values for RGB are 0 - 255. Any values that fall out of that range must be rounded to the closest valid value.

Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.

The following are examples of expected output values:

rgb(255, 255, 255) # returns FFFFFF
rgb(255, 255, 300) # returns FFFFFF
rgb(0,0,0) # returns 000000
rgb(148, 0, 211) # returns 9400D3
*******************************************************************************/

class RGBToHex
{
   public:
   static std::string rgb(int r, int g, int b);
};

std::string RGBToHex::rgb(int r, int g, int b)
{
   // Replace out of bounds values with min or max values
   r = std::max(0, r);
   r = std::min(255, r);
   g = std::max(0, g);
   g = std::min(255, g);
   b = std::max(0, b);
   b = std::min(255, b);
  
   // Format result as hex string and return
   char result[7];
   sprintf(result, "%02X%02X%02X", r, g, b);
  
   return std::string(result);
}
