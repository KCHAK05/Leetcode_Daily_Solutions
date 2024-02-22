/*
LEETCODE QUESTION : 1481 === Least Number of Unique Integers after K Removals ( MEDIUM )
Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

Example 1:
Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.

Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.

Constraints:
1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
       unordered_map<int,int>mp;
       for (auto x:arr)
       {
           mp[x]++;
       }
       vector<pair<int,int>>v;
       for (auto x:mp)v.push_back({x.second,x.first});
       sort(v.begin(),v.end(),greater<pair<int,int>>());
       int i = v.size()-1;
       while(k>0)
       {
            int val = v[i].first;
            if (k>val)
            {
                k-=val;
                v[i--].first = 0;
            }
            else if (k<=val)
            {
                v[i--].first-=k;
                k=0;
            }
       }
       
       int count = 0;
       for (auto x:v)
       {
           if (x.first!=0)count++;
       }
       return count;
       
    }
};