class Solution {
public:
    int closedIsland(vector<vector<int>>& g) {
        int n = (int)g.size();
        int m = (int)g[0].size();
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == 0){
                    count += dfs(g, i, j);
                }
            }
        }

        return count;
    }
    
private:
    int dfs(vector<vector<int>>& g, int row, int col){
        int n = (int)g.size();
        int m = (int)g[0].size();

        if(row < 0 || row >= n || col < 0 || col >= m){
            return 0;
        }

        if(g[row][col] == 1){
            return 1;
        }

        g[row][col] = 1;
        int up = dfs(g, row-1, col);
        int down = dfs(g, row+1, col);
        int left = dfs(g, row, col-1);
        int right = dfs(g, row, col+1);
        
        return up & down & left & right;
    }
};
