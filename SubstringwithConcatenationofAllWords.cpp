/*
 *brute force, but try to optimise
 */

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string,int> Lmap;
        unordered_map<string,int> tmp;
        vector<int> res;
        int len = L[0].size();
        int N = L.size();
        int M = S.size();
        
        for (int i=0; i<N; i++)
            Lmap[L[i]]++;
        int Lsize = len*N;
        
        for (int i=0; i<=M-Lsize; i++){
            int j;
            tmp.clear();
            for (j=0 ; j<N; j++){
                string x = S.substr(i+j*len,len);
                if (Lmap.find(x) == Lmap.end())
                    break;
                if (tmp[x]>=Lmap[x])
                    break;
                tmp[x]++;
            }
            if (j == N)
                res.push_back(i);
        }
        return res;
    }
};