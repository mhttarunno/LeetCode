class Solution {
public:
    int vis[1005];
    void dfs(int node, vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vis[node] = true;
        for (int i = 0; i < n; ++i) {
            if (!(isConnected[node][i] ^ 1) && !vis[i]) {
                dfs(i, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        memset(vis, false, sizeof(vis));
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, isConnected);
                count++;
            }
        }
        return count;
    }
};
