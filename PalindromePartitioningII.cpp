class Solution {
public:
    /*int minCut(string s) {// time limit exceeded
        int len = s.size();
        int dp[len+1][len];
        
        for(int i=1; i<=len; i++) {
            for(int j=0; i+j<=len; j++) {
                if(isPalin(s.substr(j, i))) {
                    dp[i][j] = 0;
                }
                for(int k=1; k<i; k++) {
                    dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j+k]);
                }
            }
        }
        return dp[len][0];
    }
    
    bool isPalin(string s) {
        for(int i=0, j=s.size()-1; i<j; i++, j--) {
            if(s[i] != s[j])
                return false;
        }
        return true;
    }*/
    
    int minCut(string s) {
        int N = s.size();
        bool isP[N];
        int dp[N];
        dp[0] = 0;
        for (int i = 1; i < N; ++i) 
        {
            isP[i] = true;
            dp[i] = dp[i-1] + 1;
            for (int j = 0; j < i; ++j) 
            {   //this is smart!!!how to judge isPalindrome.
                isP[j] = (s[i] == s[j]) ? isP[j+1] : false; // isP[j] == true   -> [j...i] is a palindrome
                                                            // isP[j+1] == true -> [j+1...i-1] is a palindrome
                if (isP[j])
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j-1] + 1);  // dp[i] -> minCount for [0...i]
            }
        }
        return dp[N-1];
    }
    
    bool isP[N];
    int dp[N];
    dp[0] = 0;
    for(int i=1; i<N; i++) {
        dp[i] = dp[i-1] + 1;
        for(int j=0; j<i; j++) {
            isP[j] = (s[j] == s[i])? isP[j+1] : false;
            if(isP[j]) 
                dp[i] = (j == 0)? 0: min(dp[i], dp[j-1] + 1);
        }
    }
    return dp[N-1];
};