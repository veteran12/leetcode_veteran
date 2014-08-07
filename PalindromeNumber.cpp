class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int z = 1;
        while(x/z > 9) z *= 10;
        
        while(z > 1) {
            int l = x % 10;
            int r = x / z;
            if(l != r)
                return false;
            x = x % z;
            x = x / 10;
            z /= 100;
        }   
        return true;
    }
};