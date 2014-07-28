class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        vector<int> tmp;
        map<int, int> record;
        for(int i=0; i<num.size(); i++){
            if(record.find(num[i]) == record.end())
                record[num[i]] = 1;
            else
                record[num[i]]++;
        }
        
        sub(res, num, tmp, num.size(), record);
        return res;
    }
    
    void sub(vector<vector<int> > &res, vector<int> &num, vector<int> tmp,int len, map<int, int> &record) {
        if(tmp.size() == len) {
            res.push_back(tmp);
            return;
        }
        
        for(int i=0; i<len; i++) {
            if(!used(record, num[i])) {
                tmp.push_back(num[i]);
                record[num[i]]--;
                sub(res, num, tmp, len, record);
                tmp.pop_back();
                record[num[i]]++;
                while(i<len-1 && num[i]==num[i+1]) i++; //eliminate repeated element!
            }
        }
        return;
    }
    
    bool used(map<int, int> &record, int x) {
        if(record[x] > 0)
            return false;
        else
            return true;
    }
};