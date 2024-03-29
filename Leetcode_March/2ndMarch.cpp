/*
LEETCODE QUESTION : 977. Squares of a Sorted Array ( EASY )

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        vector<int>result(nums.size());
        int j = nums.size()-1;
        int temp,k =nums.size()-1;
        for (k = nums.size()-1;k>=0;k--)
        {
           if (abs(nums[i])>abs(nums[j]))result[k]=nums[i]*nums[i++];
           else result[k] = nums[j]*nums[j--];
        }
        return result;
    }
};