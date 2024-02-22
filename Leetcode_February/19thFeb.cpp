/*
LEETCODE QUESTION : 231. Power of Two ( EASY )

Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:
Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 24 = 16

Example 3:
Input: n = 3
Output: false

Constraints:
-231 <= n <= 231 - 1
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n%2!=0 and n!=1 and n!=0)return false;
        double i = 1;
        if (n>=1)
        {
            while(i<=n)
            {
                if (i==n)return true;
                i=i*2;
            }
        }
        else if (n<1)
        {
            while(i<n)
            {
                if (i==n)return true;
                i=i*(1/2);
            }
        }
        return false;
    }
};