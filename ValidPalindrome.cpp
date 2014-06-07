/*
 *be careful,read carefully
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i < j){
            if(s[i]<48||s[i]>122||(s[i]>57&&s[i]<65)||(s[i]>90&&s[i]<97)){
                i++;
                continue;
            }
            if(s[j]<48||s[j]>122||(s[j]>57&&s[j]<65)||(s[j]>90&&s[j]<97)){
                j--;
                continue;
            }
            if(s[i]==s[j]||s[i]+32==s[j]||s[i]-32==s[j]){
                i++;
                j--;
            }else
                return false;
        }
        return true;
    }
};

/*
 *class Solution:
    #in python you can not use char to directly compare or calculate with integer!!!
    # @param s, a string
    # @return a boolean
    def isPalindrome(self, s):
        i = 0
        j = len(s) - 1
        while i < j:
            if s[i] < '0' or s[i] > 'z' or (s[i] > 'Z' and s[i] < 'a') or (s[i] > '9' and s[i] < 'A'):
                i = i + 1
                continue
            if s[j] < '0' or s[j] > 'z' or (s[j] > 'Z' and s[j] < 'a') or (s[j] > '9' and s[j] < 'A'):
                j = j - 1
                continue
            if s[i] == s[j] or s[i].upper() == s[j] or s[i].lower() == s[j]:
                i = i + 1
                j = j - 1
            else:
                return False
        return True
 */