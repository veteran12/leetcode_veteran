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