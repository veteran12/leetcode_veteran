class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int> > res;
        vector<int> tmp(1,1);
        res.push_back(tmp);
        
        for(int i = 1; i<=rowIndex; i++) {
            vector<int> tmp;
            for(int j=0; j<=i; j++) {
                if( j ==0 || j == i)
                    tmp.push_back(1);
                else
                    tmp.push_back(res[i-1][j]+res[i-1][j-1]);
            }
            res.push_back(tmp);
        }
        return res[rowIndex];
    }
};