/*
LEETCODE QUESTION: 349 === Intersection of Two Arrays ( EASY )

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mp1,mp2;
        for (auto x:nums1)mp1[x]++;
        for (auto x:nums2)mp2[x]++;
        for (auto x:nums1)
        {
            if (mp1[x] and mp2[x] and find(ans.begin(),ans.end(),x)==ans.end())ans.emplace_back(x);
        }
        return ans;
    }
};