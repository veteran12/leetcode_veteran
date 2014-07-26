class Solution {
public:
   /*
   time limit exceeded
   string getPermutation(int n, int k) {
        string tmp = "";
        int count = 0;// 
        return sub(n, k, count, tmp);
    }
    
    string sub(int n, int k, int &count, string tmp ) {
        if(tmp.size() == n) {
            if(count == k-1)
                return tmp;
            else {
                count++;
                return "";
            }
        }
        
        for(int i=1; i<=n; i++) {
            char cha = char('0' + i);
            if((int)tmp.find(cha) < 0) {
                tmp.push_back(cha);
                string x = sub(n, k, count, tmp);
                if(x != "")
                    return x;
                tmp.pop_back();
            }
        }
        return "";
    }*/
    
    string getPermutation(int n, int k) {
        string num, res;
        int total = 1;
        for (int i = 1; i <= n; ++i)
        {
            num.push_back(i + '0');
            total *= i;
        }
        k--;
        while (n)
        {
            total /= n;
            int i = k / total;
            k %= total;
            res.push_back(num[i]);
            num.erase(i, 1);
            n--;
        }
        return res;
    }
};