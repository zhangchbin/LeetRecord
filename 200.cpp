class Solution {
public:
    int vis[310][310];
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int m, n;
    vector<vector<char>> gg;
    int judge(int x, int y){
        return x <m && y <n && x>=0 && y >= 0 && vis[x][y] == 0 && gg[x][y] == '1';
    }
    void dfs(int i, int j){
        vis[i][j] = 1;
        for(int k=0;k<4;k++){
            int newx = i + dx[k], newy = j + dy[k];
            if(!judge(newx, newy)) continue;
            dfs(newx, newy);
        } 
    }

    int numIslands(vector<vector<char>>& grid) {
        memset(vis, 0, sizeof(vis));
        gg = grid;
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((!vis[i][j]) && grid[i][j] == '1'){
                    ans++;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};
