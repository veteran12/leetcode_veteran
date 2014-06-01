class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort( S.begin(), S.end() );
        vector<vector<int> > res;

        for( int i = 0; i <= S.size(); i++ ){
            vector<int> tmp;
            sub( res, S, tmp, 0, i);
        }
        return res;
    }
    void sub( vector<vector<int> > &res, vector<int> &S, vector<int> &tmp, int start, int length ){
        if( length == 0 ){
            res.push_back(tmp);
            return;
        }
        while( start < S.size() ){
            tmp.push_back( S[start] );
            sub( res, S, tmp, start + 1, length - 1 );
            tmp.pop_back();
            while( start + 1 < S.size() && S[start] == S[start + 1] ) //the skill to avoid duplicate subset is similar to three sum!
                start++;
            start++;
        }
        return;
    }
};

/*
 *python version
 *class Solution:
    # @param num, a list of integer
    # @return a list of lists of integer
    def subsetsWithDup(self, S):
        S.sort()
        res = []
        for i in range( len(S) + 1 ):
            tmp = []
            self.sub( res, S, tmp, 0, i )
        return res
        
    def sub(self, res, S, tmp, start, length):
        if length == 0:
            res.append(tmp[:]) //res.append(tmp) error this statement just insert a pointer which points to tmp into res,we need tmp[:] to make a copy!!! note: in  python sequence type is transfered as reference and regular type is transfered as value:)
            return
        while start < len(S):
            tmp.append(S[start])
            self.sub(res, S, tmp, start + 1, length - 1)
            del tmp[-1]
            while start + 1 < len(S) and S[start] == S[start + 1]:
                start += 1
            start += 1
        return
 */