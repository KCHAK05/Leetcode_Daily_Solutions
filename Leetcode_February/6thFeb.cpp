/*
LEETCODE QUESTION : 49 === Group Anagrams (MEDIUM)

Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Constraints:
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<vector<int>,vector<string>>mp;
        for (auto x:strs)
        {
            vector<int>count(26,0);
            for (auto c:x)count[c-'a']++;
            mp[count].emplace_back(x);
        }
        for (auto x:mp)
        {
            ans.emplace_back(x.second);
        }
        return ans;
    }
};