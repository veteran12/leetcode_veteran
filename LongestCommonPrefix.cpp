class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int N = strs.size();
        if (N == 0)
            return "";
        string prefix = strs[0];
        
        for (int i=1; i<N; i++) {
            int j = 0;
            while (prefix[j]==strs[i][j] && j<prefix.size() && j<strs[i].size())
                j++;
            prefix = prefix.substr(0,j);
        }
        return prefix;
    }
};