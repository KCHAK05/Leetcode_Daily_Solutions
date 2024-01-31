/*
LEETCODE QUESTION NUMBER->931 === Minimum Falling Path Sum ( MEDIUM )

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right.
Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.

Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<vector<int>>&matrix)
    {
        if (j<0 or j>=matrix[0].size())return 10000;
        if (i==matrix.size()-1)return matrix[i][j];
        if (dp[i][j]!=-10000)return dp[i][j];
        int sum1 = matrix[i][j] + solve(i+1,j-1,matrix);
        int sum2 = matrix[i][j] + solve(i+1,j,matrix);
        int sum3 = matrix[i][j] + solve(i+1,j+1,matrix);
        return dp[i][j] = min(sum1,min(sum2,sum3));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        dp.assign(row,vector<int>(col,-10000));
        int ans = INT_MAX;
        for (int i = 0;i<col;i++){
            ans = min(ans,solve(0,i,matrix));
        }
        return ans;
    }
};
