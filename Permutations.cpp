class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        vector<int> tmp;
        sub(res, num, tmp, num.size());
        return res;
    }
    
    void sub(vector<vector<int> > &res, vector<int> &num, vector<int> tmp,int len) {
        if(tmp.size() == len) {
            res.push_back(tmp);
            return;
        }
        
        for(int i=0; i<len; i++) {
            if(!used(tmp, num[i])) {
                tmp.push_back(num[i]);
                sub(res, num, tmp, len);
                tmp.pop_back();
            }
        }
        return;
    }
    
    bool used(vector<int> tmp, int x) {
        for(int i=0; i<tmp.size(); i++) {
            if(tmp[i] == x)
                return true;
        }
        return false;
    }
};