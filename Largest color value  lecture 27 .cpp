int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size(), ans = 0;
    vector<vector<int>> graph(n);
    vector<vector<int>> cnt(n, vector<int>(26, 0));
    vector<int> indegree(n);
    for (auto &e : edges) {
        graph[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    int processed = 0;
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        processed++;
        cnt[f][colors[f] - 'a']++;
        ans = max(ans, cnt[f][colors[f] - 'a']);
        for (auto nbr : graph[f]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
                q.push(nbr);
            for (int j = 0; j < 26; j++)
                cnt[nbr][j] = max(cnt[nbr][j], cnt[f][j]);
        }
    }
    return processed == n ? ans : -1;
}
