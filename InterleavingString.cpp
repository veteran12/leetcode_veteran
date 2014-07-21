class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        
        if (l1+l2 != l3)
            return false;
        
        bool dp[l1+1][l2+1];
        dp[0][0] = true;
        for (int i=1; i<l1+1; i++) {
            if (s1[i-1] == s3[i-1])
                dp[i][0] = true;
            else
                dp[i][0] = false;
        }
        
        for (int j=1; j<l2+1; j++) {
            if (s2[j-1] == s3[j-1])
                dp[0][j] = true;
            else
                dp[0][j] = false;
        }
        
        
        for (int i=1; i<l1+1; i++) {
            for (int j=1; j<l2+1; j++) {
                dp[i][j] = false;
                if (s1[i-1] ==  s3[i+j-1])
                    dp[i][j] = (dp[i-1][j] || dp[i][j]);
                if (s2[j-1] == s3[i+j-1])
                    dp[i][j] = (dp[i][j-1] || dp[i][j]);
            }
        }
        return dp[l1][l2];
    }
};