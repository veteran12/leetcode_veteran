class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        bool rowZero = false;
        bool colZero = false;
        
        for(int i=0; i<M; i++) {
            if(matrix[i][0] == 0) {
                rowZero = true;
                break;
            }
        }
        
        for(int i=0; i<N; i++) {
            if(matrix[0][i] == 0) {
                colZero = true;
                break;
            }
        }
        
        for(int i=1; i<M; i++) {
            for(int j=1; j<N; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0; //use first row and col to store whether should turn the whole row or column to zero
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=1; i<M; i++) {
            if(matrix[i][0] == 0) {
                for(int j=1; j<N; j++)
                    matrix[i][j] = 0;
            }
        }
        
        for(int j=1; j<N; j++) {
            if(matrix[0][j] == 0) {
                for(int i=1; i<M; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(rowZero == true) {
            for(int i=0; i<M; i++) {
                matrix[i][0] = 0;
            }
        }
        
        if(colZero == true) {
            for(int i=0; i<N; i++)
                matrix[0][i] = 0;
        }
        
        return;
    }
};