// TC : O(n*m), SC : O(1)

class Solution{
public:
    vector<int> dirx{-1,0,1, 0};
    vector<int> diry{0, 1, 0, -1};
    void floodfill(vector<vector<char>> &mat, int r, int c){
        queue<pair<int,int>> q;
        q.push({r, c});
        mat[r][c] = 'O';
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nrow = row + dirx[i];
                int ncol = col + diry[i];
                
                if(nrow < 0 || nrow >= mat.size() || ncol < 0 || ncol >= mat[0].size())
                    continue;
                
                if(mat[nrow][ncol] == '-'){
                    mat[nrow][ncol] = 'O';
                    q.push({nrow, ncol});
                }
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 'O')
                    mat[i][j] = '-';
            }
        }
        
        for(int i=0; i<n; i++){
           if(mat[i][0] == '-')
                floodfill(mat, i, 0);
            if(mat[i][m-1] == '-')
                floodfill(mat, i, m-1);
        }
        
        for(int j=0; j<m; j++){
           if(mat[0][j] == '-')
                floodfill(mat, 0, j);
            if(mat[n-1][j] == '-')
                floodfill(mat, n-1, j);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == '-')
                    mat[i][j] = 'X';
            }
        }
        
        return mat;
        
    }
};