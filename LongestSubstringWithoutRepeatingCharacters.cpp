class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int ref = -1;
        map<char, int> record;
        
        for (int i=0; i<s.size(); i++) {
           if (record.find(s[i]) == record.end()) {
               record.insert(make_pair(s[i], i));
               res = max(res, i - ref);
           } else {
               if (record[s[i]] < ref) {
                    record[s[i]] = i;
                    res = max(res, i - ref);
                    continue;
               }
               ref = record[s[i]];
               record[s[i]] = i;
               res = max(res, i - ref);
           }
        }
        return res;
    }
};