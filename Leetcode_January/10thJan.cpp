/*
LEETCODE QUESTION NUMBER -> 2385 === Amount of Time for Binary Tree to Be Infected ( MEDIUM )

You are given the root of a binary tree with unique values, and an integer start.
At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

Example 1:
Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

Example 2:
Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0

Constraints:
1. The number of nodes in the tree is in the range [1, 105].
2. 1 <= Node.val <= 105
3. Each node has a unique value.
4. A node with a value of start exists in the tree.
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
    void func1(unordered_map<int,vector<int>>&mp,TreeNode* root)
    {
        if (root==NULL)return;
        if (root->left)
        {
            mp[root->val].emplace_back(root->left->val);
            mp[root->left->val].emplace_back(root->val);
        }
        if (root->right)
        {
            mp[root->val].emplace_back(root->right->val);
            mp[root->right->val].emplace_back(root->val);
        }
        func1(mp,root->left);
        func1(mp,root->right);
    }
    void findSize(TreeNode* root,int& size)
    {
        if (root==NULL)return;
        size++;
        findSize(root->left,size);
        findSize(root->right,size);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>vis;
        func1(mp,root);
        int fullsize =0;
        findSize(root,fullsize);
        int time = -1;
        queue<int>q;
        q.emplace(start);
        while(!q.empty())
        {
            int size = q.size();
            time++;
            for (int i = 0;i<size;i++)
            {
                auto node = q.front();
                vis[node] = 1;
                q.pop();
                for (auto x:mp[node]){
                    if (vis[x]==0)
                    {
                        q.emplace(x);
                    }
                }
            }
        }
        return time;
    }
};
