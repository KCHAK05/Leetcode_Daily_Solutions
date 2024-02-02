/*
LEETCODE QUESTION : 1291 === Sequential Digits ( MEDIUM )

An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

Example 1:
Input: low = 100, high = 300
Output: [123,234]

Example 2:
Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]

Constraints:
10 <= low <= high <= 10^9
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        queue<int>q;
        for (int i = 1;i<=9;i++)
        {
            q.push(i);
            while(!q.empty())
            {
                int a = q.front();
                q.pop();
                if (a>=low and a<=high)ans.emplace_back(a);
                if (a>high)break;
                int n = a%10;
                if (n<9)
                {
                    q.push(a*10 + (n+1));
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};