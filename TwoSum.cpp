bool compare(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }


class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        vector<pair<int, int> > tmp;
        for(int i=0; i<numbers.size(); i++) {
            tmp.push_back(make_pair(numbers[i], i+1));
        }
        
        
        sort(tmp.begin(), tmp.end(), compare);
        
        int i = 0;
        int j = tmp.size() - 1;
        
        while(i < j) {
            if(tmp[i].first + tmp[j].first == target) {
                res.push_back(min(tmp[i].second, tmp[j].second));
                res.push_back(max(tmp[i].second, tmp[j].second));
                return res;
            }
            else if(tmp[i].first + tmp[j].first < target)
                i++;
            else
                j--;
        }
    }

};