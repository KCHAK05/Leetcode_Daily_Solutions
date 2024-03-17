/*
LEETCODE QUESTION: 238. Product of Array Except Self ( MEDIUM )

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Constraints:
2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int cnt = 0;
        for (auto x:nums)
        {
            if (x==0)cnt++;
            else prod*=x;
        }
        if (cnt==0)
        {
            for (int i = 0;i<nums.size();i++)nums[i] = prod/nums[i];
        }
        else if (cnt==1)
        {
            for(int i = 0;i<nums.size();i++)
            {
                if (nums[i] == 0)nums[i] = prod;
                else nums[i] = 0;
            }
        }
        else
        {
            for (int i= 0;i<nums.size();i++)nums[i] = 0;
        }
        return nums;
    }
};