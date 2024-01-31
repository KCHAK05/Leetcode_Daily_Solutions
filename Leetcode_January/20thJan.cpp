/*
LEETCODE QUESTION NUMBER->907 === Sum of Subarray Minimums  ( HARD - MEDIUM )

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
Since the answer may be large, return the answer modulo 109 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444

Constraints:
1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104

*/

// extremely good, hard and important montonic stack question !!!!

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int size = arr.size();
        int ans = 0;
        vector<long long>left(size,0),right(size,0);
        stack<pair<int,int>>sleft,sright;
        for (int i = 0;i<size;i++)
        {
            int cnt = 1;
            while(!sleft.empty() and sleft.top().first>arr[i])
            {
                cnt+=sleft.top().second;
                sleft.pop();
            }
            sleft.push({arr[i],cnt});
            left[i] = cnt;
        }
        for (int i = size-1;i>=0;i--)
        {
            int cnt = 1;
            while(!sright.empty() and sright.top().first>=arr[i])
            {
                cnt+=sright.top().second;
                sright.pop();
            }
            sright.push({arr[i],cnt});
            right[i] = cnt;
        }
        for (int i = 0 ;i<size;i++)
        {
            ans = (ans + (arr[i]*(right[i]*left[i])%mod)%mod)%mod;
        }
        return ans;
    }
};