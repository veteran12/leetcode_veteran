class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size() - 1;
        int n = 0;
        
        while(m>=0 && n<matrix[0].size()) {
            if(matrix[m][n] > target)
                m--;
            else if(matrix[m][n] < target)
                n++;
            else
                return true;
        }
        return false;
    }
};