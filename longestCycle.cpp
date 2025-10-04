class Solution {
public:
    int longestCycleLen = -1;

    void dfsFindLongestCycle(int cycleLen, int node, vector<int> &currentPath,
                             vector<int> &visitedNodeList, vector<int> &edges) {
        cycleLen++;
        currentPath[node] = cycleLen;
        visitedNodeList[node] = 1;

        int nbr = edges[node];
        if (nbr != -1) {
            if (!visitedNodeList[nbr]) {
                dfsFindLongestCycle(cycleLen, nbr, currentPath, visitedNodeList, edges);
            } 
            else if (currentPath[nbr] != 0) {
                int currCycleLen = currentPath[node] - currentPath[nbr] + 1;
                longestCycleLen = max(longestCycleLen, currCycleLen);
            }
        }
        currentPath[node] = 0;
    }

    int longestCycle(vector<int> &edges) {
        int numOfNodes = edges.size();

        vector<int> visitedNodeList(numOfNodes, 0);
        vector<int> currentPath(numOfNodes, 0);

        for (int i = 0; i <= numOfNodes - 1; i++) {
            if (visitedNodeList[i] != 1) {
                dfsFindLongestCycle(0, i, currentPath, visitedNodeList, edges);
            }
        }
        return longestCycleLen;
    }
};
