class Solution {
public:
    bool solve(int row, int col, int ind, vector<vector<char>>& board, string& word){
        //edge cases
        int n = board.size();
        int m = board[0].size();

        if(ind >= word.size()) return true;
        if(row < 0 || col < 0 || row >= n || col >= m) return false;
        if(board[row][col] != word[ind]) return false;

        //if none, that means we have found the word's char
        char temp = board[row][col];
        board[row][col] = '#';

        bool found = solve(row+1, col, ind+1, board, word) ||
                    solve(row-1, col, ind+1, board, word) ||
                    solve(row, col+1, ind+1, board, word) ||
                    solve(row, col-1, ind+1, board, word);

        board[row][col] = temp;
        return found;
        
    }
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        //important step to iterate a grid
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(solve(i, j, 0, board, word)) return true;
            }
        }

        return false;
    }
};
