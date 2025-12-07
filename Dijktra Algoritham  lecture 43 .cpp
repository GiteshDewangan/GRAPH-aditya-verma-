vector<int> dijkstra(vector<vector<pair<int,int>>> &adj, int src) {

    // Min-heap
    priority_queue<pair<int,int>, 
                   vector<pair<int,int>>, 
                   greater<pair<int,int>>> pq;

    int n = adj.size();
    vector<int> distances(n, INT_MAX);

    // Step 1: Source distance = 0
    distances[src] = 0;
    pq.push({0, src});

    // Step 2: Process pq
    while (!pq.empty()) {

        auto pr = pq.top();  
        pq.pop();

        int dist_of_node_from_src = pr.first;
        int node = pr.second;

        // Step 3: Iterate over neighbours
        for (auto &nbr_info : adj[node]) {

            int nbr = nbr_info.first;
            int weight = nbr_info.second;

            int saved_dist_of_nbr_from_src = distances[nbr];
            int new_dist_of_nbr_from_src = dist_of_node_from_src + weight;

            // Relaxation step
            if (new_dist_of_nbr_from_src < saved_dist_of_nbr_from_src) {
                distances[nbr] = new_dist_of_nbr_from_src;
                pq.push({new_dist_of_nbr_from_src, nbr});
            }
        }
    }

    // Convert unreachable nodes INT_MAX → -1
    for (int i = 0; i < n; i++) {
        if (distances[i] == INT_MAX) {
            distances[i] = -1;
        }
    }

    return distances;
}
