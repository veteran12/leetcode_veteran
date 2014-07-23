class Solution {
public:
    string intToRoman(int num) {
        int tmp = 0;
        string res = "";
        
        //deal with thousand
        tmp = num / 1000;
        num = num % 1000;
        for(; tmp>0; tmp--)
            res += "M";
        
        //deal with hundred
        tmp = num / 100;
        num = num % 100;
        if(tmp == 9)
            res += "CM";
        else if(tmp == 4)
            res += "CD";
        else if(tmp < 4)
            for(; tmp>0; tmp--)
                res += "C";
        else {
            res += 'D';
            for(; tmp-5>0; tmp--)
                res += 'C';
        }
        
        //deal with ten
        tmp = num / 10;
        num = num % 10;
        if(tmp == 9)
            res += "XC";
        else if(tmp == 4)
            res += "XL";
        else if(tmp < 4)
            for(; tmp>0; tmp--)
                res += "X";
        else {
            res += 'L';
            for(; tmp-5>0; tmp--)
                res += 'X';
        }
        
        //deal with one
        tmp = num / 1;
        num = num % 1;
        if(tmp == 9)
            res += "IX";
        else if(tmp == 4)
            res += "IV";
        else if(tmp < 4)
            for(; tmp>0; tmp--)
                res += "I";
        else {
            res += 'V';
            for(; tmp-5>0; tmp--)
                res += 'I';
        }
        
        return res;
    }
};