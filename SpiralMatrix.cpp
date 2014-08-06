vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if(matrix.empty())
            return res;
        int M=matrix.size();
        int N=matrix[0].size();
        int sum=M*N;
        for(int i=0,j=0;i<=M/2&&j<=N/2;i++,j++){
            if(res.size()==sum)
                break;
            for(int k=j;k<N-j;k++)
                res.push_back(matrix[i][k]);
            for(int k=i+1;k<M-i;k++)
                res.push_back(matrix[k][N-j-1]);
            if(res.size()==sum)
                break;
            for(int k=N-j-2;k>=j;k--)
                res.push_back(matrix[M-i-1][k]);
            for(int k=M-i-2;k>i;k--)
                res.push_back(matrix[k][j]);
        }
        return res;
    }