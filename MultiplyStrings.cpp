string multiply(string num1, string num2) {
        int i = num1.size();
        int j = num2.size();
        string res(i+j, '0');
        
        for(int m=i-1; m>=0; m--) {
            int carry = 0;
            for(int n=j-1; n>=0; n--) {
                int tmp = res[m+n+1] - '0';
                res[m+n+1] = ((num1[m] - '0') * (num2[n] - '0') + tmp +carry) % 10 + '0';
                carry = ((num1[m] - '0') * (num2[n] - '0') + tmp + carry) / 10;
            }
            res[m] += carry;
        }
        
        while (res.size() > 1 && res[0] == '0')
            res.erase(res.begin());
        
        return res;
    }