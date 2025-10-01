class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>> > adjList(n);

        for (const vector<int> &node: edges){
            int u = node[0];
            int v = node[1];
            int w = node[2];

            adjList[u].push_back({v, w});
            adjList[v].push_back({u, 2*w});
        }

        vector<int> d(n, INT_MAX);
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        pq.push({0,0});
        d[0] = 0;

        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();

            if (dist != d[u]) continue;
            if (u == n-1) return dist;

            for (auto &[v,w]: adjList[u]) {
                if (dist + w < d[v] ) {
                    d[v] = dist + w;
                    pq.push({d[v], v});
                }
            }
        }

        return -1;

    }
};