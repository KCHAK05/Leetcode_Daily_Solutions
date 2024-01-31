/*
LEETCODE QUESTION NUMBER->645 === Set Mismatch ( EASY )

You have a set of integers s, which originally contains all the numbers from 1 to n.

Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set,
which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:
Input: nums = [1,1]
Output: [1,2]

Constraints:
2 <= nums.length <= 104
1 <= nums[i] <= 104
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>mp;
        for (auto x:nums)mp[x]++;
        vector<int>ans(2,0);
        for (int i = 1;i<=nums.size();i++)
        {
            if (mp[i]==2)ans[0] = i;
            else if (mp[i]==0)ans[1] = i;
        }
        return ans;
    }
};