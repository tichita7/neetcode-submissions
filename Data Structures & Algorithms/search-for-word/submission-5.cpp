class Solution {
public:
    bool solve(int row, int col, int ind, vector<vector<char>>& board, string& word, int n, int m){
        //base case -- ordering matters
        if(ind == word.size()) return true; //we found the word that's why we moved
        if(row < 0 || row >= n || col < 0 || col >= m) return false;
        if(board[row][col] != word[ind]) return false;
        
        //now if not
        char ch = board[row][col];
        board[row][col] = '#';

        bool found = (solve(row+1, col, ind+1, board, word, n, m) ||
                    solve(row-1, col, ind+1, board, word, n, m) ||
                    solve(row, col+1, ind+1, board, word, n, m) ||
                    solve(row, col-1, ind+1, board, word, n, m) ) ;

        board[row][col] = ch; //backtrack
        return found; //if not found, return false
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(solve(i, j, 0, board, word, n, m)) return true;
            }
        }
        return false;
    }
};
