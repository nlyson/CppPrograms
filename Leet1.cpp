/******************************************************************************

  Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

*******************************************************************************/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        
        // Create map to store pairs (vector position and value)
        map<int, int> m;

        
        // Store pairs in map
        for(int i=0; i<nums.size(); i++)
            m.insert(pair<int, int>(nums[i], i));
        
        // Check for pairs taht add up to target
        for(int i=0; i<nums.size(); i++)
            if( m.find(target - nums[i]) != m.end() && m.at(target - nums[i]) != i )
            {
                return {i, m.at(target - nums[i])};
            }

        return {0, 0};
        
    }
};

int main()
{
    
    vector<int> test1{2, 7, 11, 15};
    
    vector<int> sol1 = Solution::twoSum(test1, 9);
    
    for( int num : sol1 )
        cout << num << " ";
    
    

    return 0;
}
