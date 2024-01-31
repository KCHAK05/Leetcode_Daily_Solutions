/*
LEETCODE QUESTION NUMBER->1704 === Determine if String Halves Are Alike ( EASY )

You are given a string s of even length. Split this string into two halves of equal lengths,
and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U').
Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

Example 1:
Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.

Example 2:
Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
 

Constraints:
1. 2 <= s.length <= 1000
2. s.length is even.
3. s consists of uppercase and lowercase letters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool halvesAreAlike(string str) {
        int size = str.size()/2;
        set<char>s = {'a','e','i','o','u','A','E','I','O','U'};
        int count = 0;
        for (int i = 0;i<size;i++)
        {
            if (s.find(str[i])!=s.end())count++;
        }
        for (int i = size;i<2*size;i++)
        {
            if (s.find(str[i])!=s.end())count--;
        }
        return count==0;
    }
};