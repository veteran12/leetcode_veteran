class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        vector<int> tmp;
        sub(res, num, target, 0, tmp, 0);
        return res;
    }
    
    void sub(vector<vector<int> > &res, vector<int> &candidates, int target, int sum, vector<int> tmp, int j) {
        int i = j;
        while(i < candidates.size()) {
            if(sum + candidates[i] < target) {
                tmp.push_back(candidates[i]);
                sub(res, candidates, target, sum + candidates[i], tmp, i+1);
                tmp.pop_back();
                i++;
                while(candidates[i] == candidates[i-1]) i++;
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
