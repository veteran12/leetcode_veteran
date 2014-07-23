class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if(numRows == 0)
            return res;
        vector<int> tmp(1,1);
        res.push_back(tmp);
        
        for(int i = 2; i<=numRows; i++) {
            vector<int> tmp;
            for(int j=0; j<i; j++) {
                if( j ==0 || j == i-1)
                    tmp.push_back(1);
                else
                    tmp.push_back(res[i-2][j]+res[i-2][j-1]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};