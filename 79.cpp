class Solution {
public:

    int ans = 0;
    
    int n, m;
    int vis[10][10];
    int dx[4]={-1, 1, 0, 0};
    int dy[4]={0, 0, -1, 1};

    vector<vector<char> > board;
    string word;
    bool judge(int i, int j, int t){
        return i>=0 && i < m && j >=0 && j<n && this->vis[i][j] == 0 && t < this->word.size();
    }
    int dfs(int i, int j, int t){
        if(ans) return 0;
        if(judge(i, j, t) && this->board[i][j] == this->word[t]){
            this->vis[i][j] = 1;
            if(t == this->word.size() - 1) ans=1;
        }  
        else return 0;
        for(int k=0;k<4;k++){
            int newx = dx[k] + i;
            int newy = dy[k] + j;
            dfs(newx, newy, t+1);
        }
        this->vis[i][j] = 0;
        return 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        this->board = board, this->word = word;
        for(int i=0; i< m; i++){
            for(int j=0;j<n;j++){
                ans = 0, memset(vis, 0, sizeof(vis));
                dfs(i, j, 0);
                if(ans) return true;
            }
        }
        return false;
    }
};
