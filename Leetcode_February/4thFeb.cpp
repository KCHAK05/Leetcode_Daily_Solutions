/*
LEETCODE QUESTION : 76 === Minimum Window Substring ( HARD )

Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window.
If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Constraints:
m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for (auto x:t)mp[x]++;
        int minLen = INT_MAX;
        int minStart = 0;
        int l=0,r=0;
        int counter = t.size();
        int size = s.size();
        while(r<size)
        {
            if (mp[s[r]]>0)counter--;
            mp[s[r]]--;
            r++;
            while(counter==0){
                if (minLen>r-l)
                {
                    minLen = r-l;
                    minStart = l;
                }
                mp[s[l]]++;
                if (mp[s[l]]>0)counter++;
                l++;
            }
        }
        if (minLen == INT_MAX)return "";
        return s.substr(minStart,minLen);
    }
};