class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> res;
    int countW=0;
    int countC=0;
    string tmp;
    for(int i=0;i<words.size();i++){
        countC+=words[i].size();
        countW++;
        if(countC+countW-1>L){
            countW--;
            countC-=words[i].size();
            tmp=words[i-countW];
            if(countW>1){
                int x=(L-countC)/(countW-1);
                int y=(L-countC)%(countW-1);
                if(y!=0){
                    tmp.append(1,' ');
                    y--;
                }
                tmp.append(x,' ');
                for(int j=i-countW+1;j<i;j++){
                    tmp=tmp+words[j];
                    if(j!=i-1)
                        tmp.append(x,' ');
                    if(y!=0){
                        tmp.append(1,' ');
                        y--;
                    }
                }
            }
            if(tmp.size()<L){
                tmp.append(L-tmp.size(),' ');
            }
            res.push_back(tmp);
            tmp.clear();
            countW=0;
            countC=0;
            i--;
        }
    }
    if(countW>0){
        for(int j=words.size()-countW;j<words.size()-1;j++)
            tmp=tmp+words[j]+" ";
        tmp=tmp+words[words.size()-1];
        tmp.append(L-tmp.size(),' ');
        res.push_back(tmp);
    }
    return res;
}

};