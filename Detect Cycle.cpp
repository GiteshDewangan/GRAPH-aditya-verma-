bool dfs(int node, vector<int> adj[], vector<int>& visited, int parent){
    visited[node] = 1;
    
    for(int nbr : adj[node]){
        if(!visited[nbr]){
            if(dfs(nbr, adj, visited, node)) return true;
        }
        else if(nbr != parent){
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            if(dfs(i, adj, visited, -1)) return true;
        }
    }
    return false;
}
