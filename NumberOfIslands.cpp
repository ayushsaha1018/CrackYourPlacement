// TC : O(n*m), SC : O(1)

class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<char>>& grid, int row, int col){
        queue<pair<int,int>> q;
        q.push({row, col});
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    if(i == 0 && j == 0)
                        continue;
                    
                    int nrow = r + i;
                    int ncol = c + j;
                    
                    if(nrow < 0 || nrow >= grid.size() || ncol < 0 || ncol >= grid[0].size())
                        continue;
                        
                    if(grid[nrow][ncol] == '1'){
                        grid[nrow][ncol] = '0';
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    bfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};