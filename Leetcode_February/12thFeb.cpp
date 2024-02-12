/*
LEETCODE QUESTION : 169 === Majority Element ( EASY )
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints:
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 1;
        int size = nums.size();
        int ele = nums[0];
        for(int i =1;i<size;i++)
        {
            if(nums[i]==ele)count++;
            else{
                if (count>(size/2))return ele;
                else
                {
                    ele = nums[i];
                    count = 1;
                }
            }
        }
        return ele;
    }
};