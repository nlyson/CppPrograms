/******************************************************************************

    Nathan Lyson
    Beeramid.cpp
    
Let's pretend your company just hired your friend from college and paid you a referral bonus. Awesome! To celebrate, you're taking your team out to the terrible dive bar next door and using the referral bonus to buy, and build, the largest three-dimensional beer can pyramid you can. And then probably drink those beers, because let's pretend it's Friday too.

A beer can pyramid will square the number of cans in each level - 1 can in the top level, 4 in the second, 9 in the next, 16, 25...

Complete the beeramid function to return the number of complete levels of a beer can pyramid you can make, given the parameters of:

your referral bonus, and

the price of a beer can

For example:

beeramid(1500, 2); // should === 12
beeramid(5000, 3); // should === 16

*******************************************************************************/

#include <iostream>

using namespace std;

// Returns number of complete beeramid levels
int beeramid(int bonus, double price)
{
    // Find out how many cans we can buy
    int numCans = bonus / price;
    
    // Return 0 if we have no cans
    if(numCans < 1)
        return 0;
    
    int level = 1;
    int levelCans = 1;
    
    // LevelCans is total cans at a given level.
    // We stop increasing level when this becomes more than the num of cans we have.
    while(levelCans <= numCans)
    {
        ++level;
        levelCans = levelCans + level*level;
    }
    
    return level - 1;
    
}

int main()
{
    // Test cases
    cout<< beeramid(1500, 2) << endl;
    cout<< beeramid(9, 2) << endl;
    cout<< beeramid(10, 2);

    return 0;
}
