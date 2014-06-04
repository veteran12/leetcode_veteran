/*
 *no tricky, just keep clear of each line!
 */
class Solution {
public:
    string countAndSay(int n) {
        if( n == 1 )
        return "1";
        
        string res = "1";
        
        while ( n > 1 ){
            char current = res[0];
            int count = 0;
            string tmp = "";
            for( int i = 0; i < res.size(); i++ ){
                if( current == res[i] ){
                    count++;
                }else{
                    tmp = tmp + (char)( count + '0' ) + current;
                    count = 1;
                    current = res[i];
                }
            }
            tmp = tmp + (char)( count + '0' ) + current;
            res = tmp;
            n--;
        }
        return res;
    }
};