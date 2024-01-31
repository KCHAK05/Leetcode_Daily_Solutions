/*
LEETCODE QUESTION NUMBER->2225 === Find Players With Zero or One Losses ( MEDIUM )

You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.

Example 1:
Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
Output: [[1,2,10],[4,5,7,8]]
Explanation:
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].

Example 2:
Input: matches = [[2,3],[1,3],[5,4],[6,4]]
Output: [[1,2,5,6],[]]
Explanation:
Players 1, 2, 5, and 6 have not lost any matches.
Players 3 and 4 each have lost two matches.
Thus, answer[0] = [1,2,5,6] and answer[1] = [].
 
Constraints:
1 <= matches.length <= 105
matches[i].length == 2
1 <= winneri, loseri <= 105
winneri != loseri
All matches[i] are unique.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans;
        unordered_map<int,int>won,loss;
        for (auto x:matches)
        {
            won[x[0]]++;
            loss[x[1]]++;
        }
        vector<int>zero_loss;
        vector<int>one_loss;
        for (auto x:won)
        {
            auto person = x.first;
            if (loss[person]==0)zero_loss.emplace_back(person);
        }
        for (auto x:loss)
        {
            auto person = x.first;
            if (x.second==1)one_loss.emplace_back(person);
        }
        sort(zero_loss.begin(),zero_loss.end());
        sort(one_loss.begin(),one_loss.end());
        ans.push_back(zero_loss);
        ans.push_back(one_loss);
        return ans;
    }
};