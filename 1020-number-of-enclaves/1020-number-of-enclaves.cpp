class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();

        int vis[n][m];
        int dx[4] = {1 , -1, 0 , 0};
        int dy[4] = {0, 0, 1, -1};
        int ans = 0;
        queue<pair<int,int>> q;

        memset(vis, 0, sizeof(vis));

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                    if(grid[i][j]){
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] && !vis[nx][ny]){
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!vis[i][j] && grid[i][j]){
                    ++ans;
                }
            }
        }

        return ans;   
    }
};