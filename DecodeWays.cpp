class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        int N = s.size();
        int dp[N];
        int i = 0;
        
        if(s[0] == '0')
            return 0;
        
        dp[0] = 1;
        if(s[1] == '0') {
            if(s[0] != '1' && s[0] !='2')
                return 0;
            else
                dp[1] = 1;
        } else {
            if((s[0] == '0' + 2 && s[1]< '0' + 7) || s[0] == '1')
                dp[1] = 2;
            else
                dp[1] = 1;
        }
        
        i = 2;
        while(i < N) {
            if(s[i] == '0') {
                if(s[i-1] == '0' || s[i-1] > '0' + 2)
                    return 0;
                else
                    dp[i] = dp[i-2];
            }
            else {
                dp[i] = dp[i-1];
                if((s[i-1]== '0' + 2 && s[i]< '0' + 7) || s[i-1] == '1')
                        dp[i] += dp[i-2];
            }
            i++;
        }
        return dp[N-1];
    }
};