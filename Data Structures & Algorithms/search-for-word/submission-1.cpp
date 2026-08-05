class Solution {
public:
    bool solve(int row, int col, int ind, vector<vector<char>>& board, string& word, int n, int m){
        //base cases
        if(ind == word.size()) return true;
        if(row < 0 || row >= n || col < 0 || col >= m) return false;
        if(board[row][col] != word[ind]) return false;

        //if above is not checked, then, we found the char of word
        char temp = board[row][col];
        board[row][col] = '#'; //visited

        bool found = solve(row+1, col, ind+1, board, word, n, m) || 
                    solve(row-1, col, ind+1, board, word, n, m) ||
                    solve(row, col+1, ind+1, board, word, n, m) ||
                    solve(row, col-1, ind+1, board, word, n, m) ;

        //if not then backtrack
        board[row][col] = temp;
        return found;
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
