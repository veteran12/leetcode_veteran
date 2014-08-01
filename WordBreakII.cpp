class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        if (!wordBreakPossible(s, dict)) return res;
        sub(res, s, dict, 0, "");
        return res;
    }
    
    void sub(vector<string> &res, string s, unordered_set<string> &dict, int start, string tmp) {
        if(start == s.size()) {
            res.push_back(tmp);
            return;
        }
        
        int i = 1;
        while(start+i <= s.size()) {
            if(dict.find(s.substr(start, i)) != dict.end()) {
                string x;
                if(tmp=="")
                    x=s.substr(start, i);
                else
                    x=tmp+" "+s.substr(start, i);
                sub(res, s, dict, start+i, x);
            }
            i++;
        }
        return;
    }
    
    bool wordBreakPossible(const string &s, const unordered_set<string> &dict) {
        int N = s.length();
        bool dp[N+1][N];
        for( int i = 0; i < N + 1; i++ )
            for( int j = 0; j < N; j++ )
                dp[i][j] = false;
        
        for( int i = 1; i < N + 1; i++ ){
            for( int j = 0; i + j < N + 1; j++ ){
                if( dict.find(s.substr(j,i)) != dict.end() ){
                    dp[i][j] = true;
                    continue;
                }
                for( int k = 1; k < i; k++ ){
                    if( dp[k][j] && dp[i-k][j+k] ){
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
        return dp[N][0];
    }
};