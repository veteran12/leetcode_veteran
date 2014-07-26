class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        map<string, int> tmp;
        for(int i=0; i<strs.size(); i++) {
            string x = strs[i];
            sort(x.begin(), x.end());
            if(tmp.find(x) == tmp.end())
                tmp[x] = i;
            else {
                if(tmp[x] != -1) {
                    res.push_back(strs[tmp[x]]);
                    tmp[x] = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }

};