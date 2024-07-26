class Solution {
public:
    vector<int> dijkstra(int src, vector<pair<int, int>> adj[], int n){
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                greater<pair<int,int>> > pq;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            int distance = pq.top().first;
            int city = pq.top().second;
            pq.pop();

            for(auto it : adj[city]){
                int adjCity = it.first;
                int distW = it.second;

                if(distance + distW < dist[adjCity]){
                    dist[adjCity] = distance + distW;
                    pq.push({dist[adjCity], adjCity});
                }
            }
        }

        return dist;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int, int>> adj[n];
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int minCities = INT_MAX;
        int cityNo = -1;

        for(int src = 0; src < n; src++){
            vector<int> cities = dijkstra(src, adj, n);
            int cntCities = 0;

            for(int i = 0; i < n; i++){
                if(cities[i] <= distanceThreshold) cntCities++;
            }

            if(cntCities <= minCities){
                minCities = cntCities;
                cityNo = src;
            }
        }

        return cityNo;
    }
};