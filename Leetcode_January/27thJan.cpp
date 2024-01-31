/*
LEETCODE QUESTION NUMBER->629 === K Inverse Pairs Array ( HARD )

For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].
Given two integers n and k, return the number of different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.

Example 1:
Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.

Example 2:
Input: n = 3, k = 1
Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.

Constraints:
1 <= n <= 1000
0 <= k <= 1000
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>>dp;
    int solve(int n,int k)
    {
        if (k==0)return 1;
        if (n==0)return 0;
        if (dp[n][k]!=-1)return dp[n][k];
        int count = 0;
        for (int i = 0;i<=min(n-1,k);i++)
        {
            count = (count+solve(n-1,k-i))%mod;
        }
        return dp[n][k] = count;
    }
    int kInversePairs(int n, int k) {
        dp.assign(n+1,vector<int>(k+1,-1));
        return solve(n,k);
    }
};