vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        
        int len = num.size();
        int i = 0;
        while (i < len - 2 && num[i] <= 0) {
            //while (num[i]==num[i+1]) i++;
            int j = i + 1;
            int k = len - 1;
            vector<int> tmp;
            while (j < k) {
                if (num[i]+num[j]+num[k]==0) {
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(num[k]);
                    res.push_back(tmp);
                    tmp.clear();
                    j++;
                    k--;
                    while(j<k && num[k]==num[k+1]) k--;
                    while(j<k && num[j]==num[j-1]) j++;
                } else if (num[i]+num[j]+num[k]>0) 
                    k--;
                else 
                    j++;
            }
            i++;
            while (i>0 && num[i]==num[i-1]) i++;
        }
        return res;
    }