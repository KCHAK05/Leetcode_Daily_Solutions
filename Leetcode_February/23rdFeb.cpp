/*
LEETCODE QUESTION : 787 === Cheapest Flights Within K Stops ( MEDIUM )

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example 1:
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Example 2:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

Example 3:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 

Constraints:

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for (auto x:flights)
        {
            auto from = x[0];
            auto to = x[1];
            auto cost = x[2];
            mp[from].push_back({to,cost});
        }
        queue<pair<int,int>>q;
        vector<int>dis(n,INT_MAX);
        q.push({src,0});
        while(!q.empty() and k>=0)
        {
            int size = q.size();
            for (int i = 0;i<size;i++)
            {
                auto node = q.front().first;
                auto dist = q.front().second;
                q.pop();
                if (!mp.count(node))continue;
                for (auto x:mp[node])
                {
                    int cost = x.second;
                    int neighbor = x.first;
                    if (dis[neighbor]<=cost+dist)continue;
                    dis[neighbor] = cost+dist;
                    q.push({neighbor,dis[neighbor]});
                }
            }
            k--;
        }
        return (dis[dst]==INT_MAX)?-1:dis[dst];
    }
};