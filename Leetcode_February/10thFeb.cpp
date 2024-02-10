/*
LEETCODE QUESTION : 647. Palindromic Substrings ( MEDIUM )

Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i,int j,string s)
    {
        int count = 0;
        while(i>=0 and j<s.size() and s[i--]==s[j++])
        {
            count++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int count = 0;
        int size = s.size();
        for (int i = 0;i<size;i++)
        {
            int even = solve(i,i,s);
            count+=even;
            int odd = solve(i,i+1,s);
            count+=odd;
        }
        return count;
    }
};