/* 
LEETCODE QUESTION NUMBER-> 1235 === Maximum Profit in Job Scheduling ( HARD )

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

Example 1:
Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

Example 2:
Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.

Constraints:

1 <= startTime.length == endTime.length == profit.length <= 5 * 104
1 <= startTime[i] < endTime[i] <= 109
1 <= profit[i] <= 104

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>dp;
    int solve(vector<vector<int>>&job,vector<int>&start,int size,int index)
    {
        if (index==size)return 0;
        if (dp[index]!=-1)return dp[index];
        int nextIndex = lower_bound(start.begin(),start.end(),job[index][1]) - start.begin();
        int not_take = solve(job,start,size,index+1);
        int take = job[index][2] + solve(job,start,size,nextIndex);
        return dp[index] = max(take,not_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>jobs;
        int size = startTime.size();
        for(int i = 0;i<size;i++)
        jobs.push_back({startTime[i],endTime[i],profit[i]});
        sort(jobs.begin(),jobs.end());
        for (int i = 0;i<size;i++)
        startTime[i] = jobs[i][0];
        dp.assign(size,-1);
        return solve(jobs,startTime,size,0);
    }
};