/*
LEETCODE QUESTION NUMBER -> 1026 === Maximum Difference Between Node and Ancestor ( MEDIUM )

Given the root of a binary tree, find the maximum value v for which
there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: 
any child of a is equal to b or any child of a is an ancestor of b.

Example 1:
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.

Example 2:
Input: root = [1,null,2,null,0,3]
Output: 3

Constraints:
1. The number of nodes in the tree is in the range [2, 5000].
2. 0 <= Node.val <= 105

*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void solve(TreeNode* root,int mini,int maxi,int& ans)
    {
        if (root==NULL)return;
        ans= max(ans,max(abs(root->val-mini),abs(root->val-maxi)));
        mini = min(mini,root->val);
        maxi = max(maxi,root->val);
        solve(root->left,mini,maxi,ans);
        solve(root->right,mini,maxi,ans);   

    }
    int maxAncestorDiff(TreeNode* root) {
        if (root==NULL)return 0;
        int mini = root->val,maxi = root->val;
        int ans = 0;
        solve(root,mini,maxi,ans);
        return ans;
    }
};