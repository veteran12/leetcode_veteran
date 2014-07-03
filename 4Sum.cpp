class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        
        int len = num.size();
        for(int i=0; i<len; i++) {
            if (i!=0 && num[i]==num[i-1]) continue;
            for (int j=i+1; j<len; j++) {
                if (j!=i+1 && num[j]==num[j-1]) continue;
                int m = j + 1;
                int n = len - 1;
                vector<int> tmp;
                while (m < n) {
                    if (num[i]+num[j]+num[m]+num[n] == target) {
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[m]);
                        tmp.push_back(num[n]);
                        res.push_back(tmp);
                        tmp.clear();
                        m++;
                        n--;
                        while(m<n && num[m]==num[m-1]) m++;
                        while(m<n && num[n]==num[n+1]) n--;
                    } else if (num[i]+num[j]+num[m]+num[n] < target)
                        m++;
                    else
                        n--;
                }
            }
        }
        return res;
    }
};