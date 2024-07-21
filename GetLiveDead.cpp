// TC : O(m*n), SC : O(m*n)

class Solution {
public:
    int m,n;
    vector<int> getLiveDead(vector<vector<int>>& board, int row, int col){
        vector<int> cnts(2, 0);
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                int nrow = row + i;
                int ncol = col + j;

                if(nrow < 0 || nrow >= m || ncol < 0 || ncol >= n || (i == 0 && j == 0))
                    continue;
                
                if(board[nrow][ncol] == 0)
                    cnts[0]++;
                else
                    cnts[1]++;
            }
        }

        return cnts;
    }

    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<int>> temp = board;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                vector<int> live_dead = getLiveDead(temp, i, j);
                int dead = live_dead[0];
                int live = live_dead[1];

                if(temp[i][j] == 1){
                    if(live < 2 || live > 3){
                        board[i][j] = 0;
                    }
                }
                else{
                    if(live == 3)
                        board[i][j] = 1;
                }
            }
        }
    }
};