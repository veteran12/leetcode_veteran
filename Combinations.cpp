class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> tmp;
        sub(res, tmp, n, k, 1);
        return res;
    }
    
    void sub(vector<vector<int> > &res, vector<int> tmp, int n, int k, int position) {
        if(tmp.size() == k) {
            res.push_back(tmp);
            return;
        }
        
        for(int i=position; i<=n; i++) {
            tmp.push_back(i);
            sub(res, tmp, n, k, i+1);
            tmp.pop_back();
        }
        return;
    }
};