class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        sub(res, candidates, target, 0, tmp, 0);
        return res;
    }
    
    void sub(vector<vector<int> > &res, vector<int> &candidates, int target, int sum, vector<int> tmp, int j) {
        
        for(int i=j; i<candidates.size(); i++) {
            if(sum + candidates[i] < target) {
                tmp.push_back(candidates[i]);
                sub(res, candidates, target, sum + candidates[i], tmp, i);
                tmp.pop_back();
            }
            else if(sum + candidates[i] == target) {
                tmp.push_back(candidates[i]);
                sort(tmp.begin(), tmp.end());
                res.push_back(tmp);
                return;
            }
            else
                return;
        }
        return;
    }
};