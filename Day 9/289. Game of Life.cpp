class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int row = i;
                int col = j;

                int cnt = 0;
                for(int x = 0; x < 8; x++){
                    int newRow = row + dx[x];
                    int newCol = col + dy[x];

                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m){
                        if(board[newRow][newCol] == 1) cnt++;
                    }
                }
                cout<<cnt<<" ";
                if(board[row][col] == 1){
                    if(cnt == 2 || cnt == 3) ans[row][col] = 1;
                    else ans[row][col] = 0;
                }
                else{
                    if(cnt == 3) ans[row][col] = 1;
                    else ans[row][col] = 0;
                }
            }
            cout<<endl;
        }


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                board[i][j] = ans[i][j];
            }
        }
    }
};