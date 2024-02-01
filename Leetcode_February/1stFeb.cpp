/*
LEETCODE QUESTION : 2966 === Divide Array Into Arrays With Max Difference ( MEDIUM )

You are given an integer array nums of size n and a positive integer k.

Divide the array into one or more arrays of size 3 satisfying the following conditions:

Each element of nums should be in exactly one array.
The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, return an empty array.
And if there are multiple answers, return any of them.

Example 1:
Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
Output: [[1,1,3],[3,4,5],[7,8,9]]
Explanation: We can divide the array into the following arrays: [1,1,3], [3,4,5] and [7,8,9].
The difference between any two elements in each array is less than or equal to 2.
Note that the order of elements is not important.

Example 2:
Input: nums = [1,3,3,2,7,3], k = 3
Output: []
Explanation: It is not possible to divide the array satisfying all the conditions.

Constraints:
n == nums.length
1 <= n <= 105
n is a multiple of 3.
1 <= nums[i] <= 105
1 <= k <= 105
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int size =nums.size();
        vector<vector<int>>ans(size/3,vector<int>(3,0));
        int index = 1;
        ans[0][0] = nums[0];
        for (int i = 0;i<size/3;i++)
        {
            for (int j = 0;j<3;j++)
            {
                if (i==0 and j==0)continue;
                if (j==0)ans[i][j] = nums[index];
                else if (nums[index]-nums[index-1]<=k)ans[i][j] = nums[index];
                else return {};
                index++;
            }
            if (ans[i][2]-ans[i][0]>k)return {};
        }
        return ans;
    }
};