/*
LEETCODE QUESTION NUMBER->1239 === Maximum Length of a Concatenated String with Unique Characters ( MEDIUM )

You are given an array of strings arr.
A string s is formed by the concatenation of a subsequence of arr that has unique characters.
Return the maximum possible length of s.
A subsequence is an array that can be derived from another array by deleting some
or no elements without changing the order of the remaining elements.

Example 1:
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

Example 2:
Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").

Example 3:
Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.
 

Constraints:
1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int index,vector<string>&arr,unordered_map<char,int>&mp)
    {
        if (index>=arr.size())return 0;
        int not_take = 0,take = 0;
        int flg = 1;
        for (auto x:arr[index])mp[x]++;
        for (auto x:mp)if (x.second>1)flg = 0;
        if (flg)take = arr[index].size() + solve(index+1,arr,mp);
        for (auto x:arr[index])mp[x]--;
        not_take = solve(index+1,arr,mp);
        return max(not_take,take);
    }
    int maxLength(vector<string>& arr) {
        int size = arr.size();
        unordered_map<char,int>mp;
        return solve(0,arr,mp);
    }
};
