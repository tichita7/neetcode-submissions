class Solution {
public:
    bool solve(int r, int c, int ind, vector<vector<char>>& board, string word, int n, int m){
        //edge cases
        if(ind == word.size()) return true;
        if(r < 0 || c < 0 || r >= n || c >= m) return false;
        if(board[r][c] != word[ind]) return false;

        //if none of the above, that means we have found the char of word
        char temp = board[r][c];
        board[r][c] = '#';

        //let's traverse in four directions
        bool found = solve(r+1, c, ind + 1, board, word, n, m) ||
                    solve(r-1, c, ind + 1, board, word, n, m) ||
                    solve(r, c+1, ind + 1, board, word, n, m) ||
                    solve(r, c-1, ind + 1, board, word, n, m);

        //backtrack
        board[r][c] = temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(solve(i, j, 0, board, word, n, m)) return true;;
            }
        }
        return false;
    }
};
