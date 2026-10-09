class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        //make first row and first column as the markers
        //whenever there is a zero, we will mark that row and column zero
        //two extra bool flags to track if any og row or column is 0

        bool isrow = false;
        bool iscol = false;

        for(int i = 0; i<n; i++){
            if(matrix[i][0] == 0) {
                iscol = true;
                break;
            }
        }

        for(int i = 0; i<m; i++){
            if(matrix[0][i] == 0) {
                isrow = true;
                break;
            }
        }

        //now mark the first row and column zero accordingly
        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        //now afte marking, make the full row and col zero
        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(isrow){
            for(int i = 0; i<m; i++){
                matrix[0][i] = 0;
            }
        }

        if(iscol){
            for(int i = 0; i<n; i++){
                matrix[i][0] = 0;
            }
        }
    }
};
