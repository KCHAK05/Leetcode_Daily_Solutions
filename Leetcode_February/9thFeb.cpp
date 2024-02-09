/*
LEETCODE QUESTION : 368 === Largest Divisible Subset

Given a set of distinct positive integers nums, return the largest subset 
answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0

If there are multiple solutions, return any of them.

Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8]

Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        vector<int>dp(size,1);
        vector<int>prev(size,-1);
        int index = 0;
        for (int i = 0;i<size;i++)
        {
            for (int j = i-1;j>=0;j--)
            {
                if (nums[i]%nums[j]==0 and dp[i]<=dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                }
            }
            if (dp[i]>dp[index])index=i;
        }
        vector<int>ans;
        while(index>=0)
        {
            ans.emplace_back(nums[index]);
            index = prev[index];
        }
        return ans;
    }
};