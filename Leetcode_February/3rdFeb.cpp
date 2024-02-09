/*
LEETCODE QUESTION : 1043. Partition Array for Maximum Sum ( MEDIUM )

Given an integer array arr, partition the array into (contiguous) subarrays of length at most k.
After partitioning, each subarray has their values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

Example 1:
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]

Example 2:
Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83

Example 3:
Input: arr = [1], k = 1
Output: 1

Constraints:
1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n, k;
    vector<int> dp;// dp[i]= max sum for arr[0:i]
    int f(int i, vector<int>& arr){
        if (i<=0) return 0;
        if (dp[i]!=-1) return dp[i];
        int ans=0, maxA=0;
        for (int j=1; j<=k && i-j>=0; j++) {
            maxA=max(maxA, arr[i-j]); // Find max value in the current partition
            ans=max(ans, f(i-j, arr)+j*maxA);
        }
        return dp[i]=ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->k=k;
        n=arr.size();
        dp.assign(n+1, -1);
        return f(n, arr);       
    }
};
