class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int len = s.size();
        
        int i = 0;
        //deal with thousand
        while(s[i] == 'M') {
            res += 1000;
            i++;
        }
        
        //deal with hundred
        while(s[i]=='C' || s[i]=='D' || s[i]=='M') {
            if(s[i] == 'C')
                res += 100;
            if(s[i] == 'D') {
                if(s[i-1] == 'C')
                    res += 300;
                else
                    res += 500;
            }
            if(s[i] == 'M')
                res += 800;
            i++;
        }
        
        //deal with ten
        while(s[i]=='X' || s[i]=='L' || s[i]=='C') {
            if(s[i] == 'X')
                res += 10;
            if(s[i] == 'L') {
                if(s[i-1] == 'X')
                    res += 30;
                else
                    res += 50;
            }
            if(s[i] == 'C') {
                res += 80;
            }
            i++;
        }
        
        //deal with one
        while(s[i]=='X' || s[i]=='I' || s[i]=='V') {
            if(s[i] == 'I')
                res += 1;
            if(s[i] == 'V') {
                if(s[i-1] == 'I')
                    res += 3;
                else
                    res += 5;
            }
            if(s[i] == 'X') {
                res += 8;
            }
            i++;
            if(i >= len)
                break;
        }
        return res;
    }
};