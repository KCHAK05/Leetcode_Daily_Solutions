/*

LEETCODE QUESTION NUMBER -> 300 === Longest Increasing Subsequence ( MEDIUM )
Given an integer array nums, return the length of the longest strictly increasing 
subsequence.

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

Constraints:
1 <= nums.length <= 2500
-104 <= nums[i] <= 104

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>dp;
    int solve(int index,int pre,vector<int>&nums,int size)
    {
        if (index==size)return 0;
        if (dp[index][pre+1]!=-1)return dp[index][pre+1];
        int len = 0 ;
        len = solve(index+1,pre,nums,size);
        if (pre==-1 or nums[pre]<nums[index])len = max(len,1 + solve(index+1,index,nums,size));
        return dp[index][pre+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        dp.assign(size+1,vector<int>(size + 1,-1));
        return solve(0,-1,nums,size);
    }
};
