/*
LEETCODE QUESTION NUMBER->576 === Out of Boundary Paths ( MEDIUM )

There is an m x n grid with a ball.
The ball is initially at the position [startRow, startColumn].
You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary).
You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn,
return the number of paths to move the ball out of the grid boundary.
Since the answer can be very large, return it modulo 109 + 7.

Example 1:
Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

Example 2:
Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12

Constraints:
1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod = 1e9+7;
    vector<vector<vector<int>>>dp;
    int solve(int i,int j,int m,int n,int res,int max)
    {
        if (res==max)
        {
            if (i<0 or j<0 or i>=m or j>=n)return 1;
            return 0;
        }
        if (i<0 or j<0 or i>=m or j>=n)return 1;
        if (dp[i][j][res]!=-1)return dp[i][j][res];
        return dp[i][j][res] = (((solve(i+1,j,m,n,res+1,max)+solve(i-1,j,m,n,res+1,max))%mod + solve(i,j+1,m,n,res+1,max))%mod + solve(i,j-1,m,n,res+1,max))%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.assign(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return solve(startRow,startColumn,m,n,0,maxMove)%mod;
    }
};
